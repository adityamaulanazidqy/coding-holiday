package helpers

import (
	"bufio"
	"fmt"
	"os"
	"os/exec"
	"strconv"
	"strings"
)

func Title(str string) {
	fmt.Printf("\n%s %s %s\n", strings.Repeat("=", 8), str, strings.Repeat("=", 8))
}

func Line() {
	fmt.Println(strings.Repeat("=", 24))
}

func clearTrim(input string) string {
	input = strings.Trim(input, "\n")
	input = strings.TrimSpace(input)
	return input
}

func InputStr(str string, reader *bufio.Reader) (string, error) {
	fmt.Print(str)
	input, err := reader.ReadString('\n')
	if err != nil {
		return "", err
	}

	input = clearTrim(input)

	return input, nil
}

func InputInt(str string, reader *bufio.Reader) (int, error) {
	fmt.Print(str)
	input, err := reader.ReadString('\n')
	if err != nil {
		return 0, err
	}

	input = clearTrim(input)

	inputInt, err := strconv.Atoi(input)
	if err != nil {
		return 0, err
	}

	return inputInt, nil
}

func ClearScreen() {
	cmd := exec.Command("clear || cls")
	cmd.Stdout = os.Stdout
	cmd.Run()
}
