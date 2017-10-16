// MURAT ORTAK 125312157 11-12-2016
#ifndef SICT_ERROR_H__
#define SICT_ERROR_H__
#include<ostream>
namespace ict{
  class Error{
	char* message_;
  public:
	Error();
	Error(const char* Error);
	Error(const Error& em) = delete;
	Error& operator=(const Error& em) = delete;
	Error& operator=(const char* errorMessage);
	virtual ~Error();
	void clear();
	bool isClear() const;
	void message(const char* value);
	const char* message()const {return message_;};
  };
  // operator<< overload prototype
	std::ostream& operator<<(std::ostream& out, const Error& E); 
}
#endif

