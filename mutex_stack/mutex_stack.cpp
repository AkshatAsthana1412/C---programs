/*
a stack which can be used by only one instance at a time, although each instance has it's own stack
*/
#include <iostream>
#include <list>
using namespace std;

class stack{
	list<int> st;
	static stack* status;
	// const int size;
	public:
		static stack* get_status(){
			return status;
		}
		void lock(){
			status = this;
		}
		void unlock(){
			if (status == this){
				status = 0;
				cout << "Stack freed!\n";
			}
			else{
				cout << "Can't unlock before lock\n";
			}
		}
		void push(int ele){
			if (status == this){
				st.push_back(ele);
			}
			else{
				cout << "Access denied! Stack currently in use \n";
			}
		}
		int pop(){
			if (status == this){
				int ele = st.back();
				st.pop_back();
				return ele;
			}
			else{
				cerr << "Access denied! Stack currently in use\n";
				exit(1);
			}
		}
};

stack* stack::status = 0;
int main() {
	// your code goes here
	stack s1, s2;
	s1.lock();
	s1.push(5);
	s1.push(10);
	cout << s1.pop() << endl;
	s2.push(4);
	s2.unlock();
	s1.unlock();
	cout << "works fine";
	return 0;
}