package main

import (
	"bufio"
	"fmt"
	"lift-simulation/helpers"
	"lift-simulation/storage"
	"lift-simulation/views"
	"os"
)

func main() {
	views.ViewLift(storage.LiftPosition, nil)

	reader := bufio.NewReader(os.Stdin)
	passenger, err := helpers.InputInt("Input the number of passengers: ", reader)
	if err != nil {
		panic(err)
	}

	if passenger < 0 {
		fmt.Println("Passenger cannot be negative")
		return
	}

	storage.Passenger = passenger

	for i := 1; i <= storage.Passenger; i++ {
		helpers.Line()
		fmt.Printf("Passenger %d: ", i)
		destinationFloor, err := helpers.InputInt("Input the destination floor: ", reader)
		if err != nil {
			panic(err)
		}

		if destinationFloor < 1 || destinationFloor > storage.Building {
			fmt.Printf("Invalid floor! Please choose between 1 and %d\n", storage.Building)
			i--
			continue
		}

		if destinationFloor == storage.LiftPosition {
			helpers.Line()
			fmt.Println("The lift is already on the destination floor")
			i--
			continue
		}

		storage.FloorDestination = append(storage.FloorDestination, destinationFloor)
	}

	for len(storage.FloorDestination) != 0 {
		floor := storage.FloorDestination[0]
		views.ViewLift(floor, reader)
	}

	fmt.Println("Successfully completed!")
}
