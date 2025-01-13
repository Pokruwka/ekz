/*Основные принципы ООП
1. Инкапсуляция
Инкапсуляция — это принцип, который позволяет скрыть внутренние детали реализации объекта и предоставлять доступ к ним только через определённые методы. Это помогает защитить данные и уменьшить зависимость между компонентами.

Пример:

package main

import "fmt"

// Определяем структуру с приватным полем
type Account struct {
	balance float64 // приватное поле
}

// Метод для получения баланса
func (a *Account) GetBalance() float64 {
	return a.balance
}

// Метод для внесения средств
func (a *Account) Deposit(amount float64) {
	if amount > 0 {
		a.balance += amount
	}
}

func main() {
	account := Account{}
	account.Deposit(100)
	fmt.Println("Баланс:", account.GetBalance()) // Вывод: Баланс: 100
}

2. Наследование
Наследование позволяет создавать новые структуры на основе существующих, унаследовав их свойства и методы. В Go наследование реализуется через встраивание.

Пример:
package main

import "fmt"

// Определяем базовую структуру
type Animal struct {
	Name string
}

// Метод для базовой структуры
func (a *Animal) Speak() {
	fmt.Println("Я животное:", a.Name)
}

// Определяем структуру, которая наследует Animal
type Dog struct {
	Animal // встраивание
	Breed  string
}

// Переопределяем метод Speak
func (d *Dog) Speak() {
	fmt.Println("Я собака породы", d.Breed, "и меня зовут", d.Name)
}

func main() {
	dog := Dog{Animal: Animal{Name: "Бобик"}, Breed: "Шарик"}
	dog.Speak() // Вывод: Я собака породы Шарик и меня зовут Бобик
}
3. Полиморфизм
Полиморфизм позволяет использовать один интерфейс для работы с различными типами. Это означает, что разные структуры могут реализовывать один и тот же метод по-разному.

Пример:
package main

import "fmt"

// Определяем интерфейс
type Speaker interface {
	Speak()
}

// Определяем структуру Cat
type Cat struct {
	Name string
}

// Реализуем метод Speak для Cat
func (c *Cat) Speak() {
	fmt.Println("Я кот по имени", c.Name)
}

// Определяем структуру Dog
type Dog struct {
	Name string
}

// Реализуем метод Speak для Dog
func (d *Dog) Speak() {
	fmt.Println("Я собака по имени", d.Name)
}

// Функция, принимающая интерфейс Speaker
func MakeSpeak(s Speaker) {
	s.Speak()
}

func main() {
	cat := Cat{Name: "Мурка"}
	dog := Dog{Name: "Шарик"}

	MakeSpeak(&cat) // Вывод: Я кот по имени Мурка
	MakeSpeak(&dog) // Вывод: Я собака по имени Шарик
}
*/