package main

import "fmt"

func GetPermutations(s []rune, index int, result *[]string) {
	if index == len(s) {
		c := make([]rune, len(s))
		copy(c, s)
		*result = append(*result, string(c))
		return
	}

	for i := index; i < len(s); i++ {
		s[i], s[index] = s[index], s[i]
		GetPermutations(s, index+1, result)
		s[i], s[index] = s[index], s[i]
	}
}

func GetAllPermutations(s string) []string {
	var result []string
	GetPermutations([]rune(s), 0, &result)
	return result
}

func main() {
	for {
		fmt.Print("The string: ")
		var str string
		fmt.Scan(&str)
		if str == "q" || str == "Q" {
			break
		}

		fmt.Println("The permutations of string \"", str, "\" are ", GetAllPermutations(str))
	}
}
