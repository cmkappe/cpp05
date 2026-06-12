# pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

	protected:
		virtual void executeAction() const;

	private:
		const std::string target;
};
