#include <vector>
#include <iostream>
#include <thread>

template <typename T>
void push(std::vector<T>& stack, const T& t) {
	stack.push_back(t);
}

template <typename T>
void pop(std::vector<T>& stack) {
	if (stack.empty()) throw std::out_of_range("Stack<>::pop(): empty stack");
	stack.pop_back();
}

template <typename T>
const T& peek(const std::vector<T>& stack) {
	if (stack.empty()) throw std::out_of_range("Stack<>::pop(): empty stack");
	return stack.back();
}

template <typename T>
bool isEmpty(const std::vector<T>& stack) {
	return stack.empty();
}

template <typename T>
void displayAll(const std::vector<T>& stack) {
	for (const T& t : stack) std::cout << t << ", ";
}

int main() {

	std::vector<char> slova;
	std::vector<int> brojevi;

	push(slova, 'a');
	push(slova, 'b');
	push(slova, 'c');
	push(slova, 'd');

	push(brojevi, 1);
	push(brojevi, 2);
	push(brojevi, 3);

	displayAll(slova);
	displayAll(brojevi);

	std::this_thread::sleep_for(std::chrono::seconds(3));

	system("cls");

	std::cout << peek(slova);

	std::this_thread::sleep_for(std::chrono::seconds(2));

	system("cls");

	pop(slova);

	displayAll(slova);
	std::cout << isEmpty(brojevi);

	return 0;
}