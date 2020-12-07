#pragma once
class Iterator {
public:
	virtual int next() = 0; //go to the next email, return the current email
	virtual bool has_next() = 0; //checking the existence of the next email
};