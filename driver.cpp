#include "Array.h"
#include "Fixed_Array.h"
#include "Stack.h"
#include "Queue.h"

#include <iostream>
#include <stdexcept>
#include <exception>

void ar();
void fa();
void st();
void qu();

using namespace std;

int main (int argc, char * argv [])
{
	cout<<"driver"<<endl;
	ar();
	fa();
	st();
	qu();
	cout<<"the end"<<endl;
  return 0;
}

void ar(void){
	cout<<endl<<endl<<"Array"<<endl<<endl;

	Array <int> a1;
	Array <char> a2;
	Array <char> a3(11);
	Array <char> a4(12, 'z');
	Array <char> a5(a4);
	Array <char> a6(25);
	Array <char> a7(25, 'y');
	const Array <char> a8(33);

	a4 = a4;
	a6 = a7;

	a7.size();
	a7.max_size();

	for (int i = 0; i < 9; i++){
		a7[i]='a';
	}
	cout<<"a7: ";
	cout<<a7.size()<<"  ";
	cout<<a7.max_size()<<endl;
	for (int i = 0; i < a7.size(); i++){
		cout<<a7[i]<<"-";
	}
	cout<<endl<<endl;

	a7.resize(15);
	cout<<"a7(15): ";
	cout<<a7.size()<<"  ";
	cout<<a7.max_size()<<endl;
	for (int i = 0; i < a7.size(); i++){
		cout<<a7[i]<<"-";
	}
	cout<<endl<<endl;

	try{
		a7[20]='l';
	}
	catch (std::out_of_range& oor){
		std::cerr<<oor.what()<<std::endl;
	}

	cout<<"15: "<<a7.size()<<" 25: "<<a7.max_size()<<endl;
	a7.shrink();
	cout<<"15: "<<a7.size()<<" 15: "<<a7.max_size()<<endl;


	
	cout<<"a7(35): ";
	cout<<a7.size()<<"  ";
	cout<<a7.max_size()<<endl;
	for (int i = 0; i < a7.size(); i++){
		cout<<a7[i]<<"-";
	}
	cout<<endl<<endl;


	if (a6 == a7){
		cout<<"good"<<endl;
	}
	else{
		cout<<"bad"<<endl;
	}
	if (a8 != a7){
		cout<<"good"<<endl;
	}
	else{
		cout<<"bad"<<endl;
	}

	a3[5]='p';
	a3.reverse();

	Array <bool> a9(10);
	a9.resize(5);
	a9.resize(5);
	a9.resize(15);
	a9.fill(false);

	a9.resize(3);
	a9[0]=true;
	a9.shrink();

	a9.reverse();
	
	Array <int> a10(20);
	a10.resize(0);
	
	try{
		a3.find('p', 12);
	}
	catch (std::out_of_range& oor){
		std::cerr<<oor.what()<<std::endl;
	}

	try{
		a5.set(0, 8);
	}
	catch (std::out_of_range& oor){
		std::cerr<<oor.what()<<std::endl;
	}
	

	try{
		a1.set(3, 7);
	}
	catch (std::out_of_range& oor){
		std::cerr<<oor.what()<<std::endl;
	}
	

	try{
		a3.set(0, 'j');
	}
	catch (std::out_of_range& oor){
		std::cerr<<oor.what()<<std::endl;
	}
	

	try{
		a3.set(70, 'j');
	}
	catch (std::out_of_range& oor){
		std::cerr<<oor.what()<<std::endl;
	}
	
	try{
		a3.set(12, 'j');
	}
	catch (std::out_of_range& oor){
		std::cerr<<oor.what()<<std::endl;
	}

	try{
		cout<<a8[33]<<endl;
	}
	catch (std::out_of_range& oor){
		std::cerr<<oor.what()<<std::endl;
	}

	try{
		a3.get(12);
	}
	catch (std::out_of_range& oor){
		std::cerr<<oor.what()<<std::endl;
	}
}

void fa(void){
	cout<<endl<<endl<<"Fixed Array"<<endl<<endl;

	Fixed_Array <char, 7> f2;
	Fixed_Array <char, 9> f3('y');
	Fixed_Array <int, 11> f4(3);
	Fixed_Array <int, 13> f5;
	Fixed_Array <int, 11> f6(5);
	Fixed_Array <int, 15> f7;
	Fixed_Array <int, 11> f8(3);

	cout<<"7: "<<f2.size()<<endl;
	cout<<"11: "<<f6.size()<<endl;

	for (int i=0; i<9; i++){
		f6[i]=i;
	}

	f6 = f6;
	f8 = f6;

	Fixed_Array <int, 11> copied(f6);

	Fixed_Array <int, 11> w;
	w = f6;

	cout<<"4: "<<f6.find(4)<<endl;

	f6.reverse();

	for (int i=0; i<9; i++){
		cout<<f6.get(i)<<"-";
	}
	cout<<endl;
	for (int i=0; i<9; i++){
		f6.set(i, 0);
	}

	if (f6 != f7){
		cout<<"good"<<endl;
	}
	else{
		cout<<"bad"<<endl;
	}
	if (f6 == f6){
		cout<<"good"<<endl;
	}
	else{
		cout<<"bad"<<endl;
	}
	if (f4 == f8){
		cout<<"good"<<endl;
	}
	else{
		cout<<"bad"<<endl;
	}
}

void st(void){
	cout<<endl<<endl<<"Stack"<<endl<<endl;

	Stack <int> s1;
	Stack <char> s2;
	Stack <int> s4;
	
	s1.is_empty() ? cout<<"good"<<endl: cout<<"bad"<<endl;
	cout<<"0: "<<s1.size()<<endl;
	for (int i=0; i<10; i++){
		s1.push(i);
	}
	s1.is_empty() ? cout<<"bad"<<endl: cout<<"good"<<endl;
	cout<<"10: "<<s1.size()<<endl;

	cout<<"copied"<<endl;
	Stack <int> s3(s1);
	cout<<s3.size()<<endl;
	for (int i=0; i<10; i++){
		cout<<s3.top()<<"-";
		s3.pop();
	}
	cout<<endl;
	s3.is_empty() ? cout<<"good"<<endl: cout<<"bad"<<endl;

	cout<<"============test"<<endl;
	s4 = s1;
	s4.is_empty() ? cout<<"bad"<<endl: cout<<"good"<<endl;
	for (int i=0; i<10; i++){
		cout<<s4.top()<<"-";
		s4.pop();
	}
	cout<<endl;
	s4.is_empty() ? cout<<"good"<<endl: cout<<"bad"<<endl;
	
	s3 = s3;


	Stack <int> s9;
	for (int i = 0; i < 100; i++){
		s9.push(6);
	}
	s4 = s9;


	for (int i=0; i<10; i++){
		cout<<s1.top()<<endl;
		s1.pop();
	}
	s1.is_empty() ? cout<<"good"<<endl: cout<<"bad"<<endl;

	//exception handling
	cout<<endl<<"exception Handling"<<endl<<endl;
	try{
		s1.pop();
	}
	catch (exception& empty_exception){
		std::cerr<<empty_exception.what()<<std::endl;
	}
	s1.clear();
	s3.clear();
	cout<<"0: "<<s3.size()<<endl;
	s3.push(7);
	cout<<"7: "<<s3.top()<<endl;
}

void qu(void){
	cout<<endl<<endl<<"Queue"<<endl<<endl;
	Queue <int> q1;
	Queue <char> q2;
	Queue <int> q3;
	Queue <int> q5;

	q1.is_empty() ? cout<<"good"<<endl : cout<<"bad"<<endl;
	cout<<"0: "<<q1.size()<<endl;
	
	for (int i=0; i<10; i++){
		q1.enqueue(i);
	}

	q1.is_empty() ? cout<<"bad"<<endl : cout<<"good"<<endl;
	cout<<"10: "<<q1.size()<<endl;


	q3 = q1;
	q3.is_empty() ? cout<<"bad"<<endl : cout<<"good"<<endl;
	cout<<"10: "<<q3.size()<<endl;

	q3 = q3;

	Queue <int> q4(q3);
	q4.is_empty() ? cout<<"bad"<<endl : cout<<"good"<<endl;
	cout<<"10: "<<q4.size()<<endl;

	q4.clear();
	q4.is_empty() ? cout<<"good"<<endl : cout<<"bad"<<endl;

	Queue <int> bigCopy;

	for (int i = 0; i < 150; i++){
		bigCopy.enqueue(8);
	}
	cout<<"150: "<<bigCopy.size()<<endl;
	q4 = bigCopy;
	cout<<"q4 150: "<<q4.size()<<endl;


	cout<<"exception handling"<<endl;
	q1.clear();
	try{
		q1.dequeue();
	}
	catch (exception& empty_exception){
		std::cerr<<empty_exception.what()<<std::endl;
	}
	q1.clear();
	cout<<"0: "<<q1.size()<<endl;
	q1.is_empty() ? cout<<"good"<<endl : cout<<"bad"<<endl;
	q1.enqueue(7);
	cout<<"7: "<<q1.dequeue()<<endl;
}
