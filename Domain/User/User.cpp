#include "User.hpp"
#include <string>
#include <vector>
using namespace std;
bool User::getMembership() {
	return membership;
}
void User::setMembership(bool isMember) {
	membership = isMember;
}
std::string User::getUsername() {
	return username;
}
vector<string> User::getOptions() {
	vector<string> options;
	options.push_back("View Personal Progress");

}