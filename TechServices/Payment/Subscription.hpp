#pragma once
#ifndef SUBSCRIPTION_H
#define SUBSCRIPTION_H
#include <string>
#include <iostream>
#include <ctime>

using namespace std;
#pragma once
class Subscription
{
private:
	time_t expirationDate();
	bool activateMembership();
public:
	bool membershipActive;
};

#endif