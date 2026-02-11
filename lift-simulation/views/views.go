package views

import (
	"bufio"
	"fmt"
	"lift-simulation/helpers"
	"lift-simulation/storage"
	"time"
)

func ViewLift(target int, reader *bufio.Reader) {
	step := 1
	if target < storage.LiftPosition {
		step = -1
	}

	for {
		helpers.ClearScreen()
		helpers.Title("LIFT SIMULATION")
		fmt.Printf("Current Position: %d | Target: %d | Passengers: %d\n", storage.LiftPosition, target, storage.Passenger)
		helpers.Line()

		for i := storage.Building; i >= 1; i-- {
			if i == storage.LiftPosition {
				fmt.Printf("|\t[%2d] LIFT\t|\n", i)
			} else {
				fmt.Printf("|\t Floor %2d \t|\n", i)
			}
		}
		helpers.Line()

		if storage.LiftPosition == target {
			break
		}

		time.Sleep(200 * time.Millisecond)
		storage.LiftPosition += step
	}

	if reader != nil {
		newDestinations := []int{}
		removedCount := 0
		for _, floor := range storage.FloorDestination {
			if floor == target {
				removedCount++
			} else {
				newDestinations = append(newDestinations, floor)
			}
		}
		storage.FloorDestination = newDestinations
		storage.Passenger -= removedCount
		if storage.Passenger < 0 {
			storage.Passenger = 0
		}

		fmt.Printf("\nArrived at floor %d. %d passenger(s) got out.\n", target, removedCount)
		fmt.Printf("Current passengers: %d\n", storage.Passenger)

		isValid := false

		for !isValid {
			isAddPassenger, err := helpers.InputStr("Do you want to add a passenger? (y/n): ", reader)
			if err != nil {
				panic(err)
			}

			if isAddPassenger == "y" || isAddPassenger == "Y" {
				floorDestination, err := helpers.InputInt("Input the destination floor: ", reader)
				if err != nil {
					panic(err)
				}

				if floorDestination < 1 || floorDestination > storage.Building {
					fmt.Printf("Invalid floor! Please choose between 1 and %d\n", storage.Building)
					continue
				}

				if floorDestination == storage.LiftPosition {
					fmt.Println("You are already on this floor!")
					continue
				}

				storage.FloorDestination = append(storage.FloorDestination, floorDestination)
				storage.Passenger++
				isValid = true
			} else if isAddPassenger == "n" || isAddPassenger == "N" {
				isValid = true
			} else {
				fmt.Println("Please enter y or n")
			}
		}
	}
}
