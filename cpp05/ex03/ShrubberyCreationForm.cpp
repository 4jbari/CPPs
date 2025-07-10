#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"


ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target ("Default")
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) 
{
	target = other.target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this == &other)
		return (*this);
	AForm::operator=(other);
	target = other.target;
	return (*this);

}


void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);

	std::ofstream outfile(target + "_shrubbery");
	if (!outfile)
	{
		std::cerr << "openning the Shrubbery file failed" << std::endl;
		return ;
	}

outfile << "                                  # #### ####			\n";
outfile << "                                ### /#|### |/####		\n";	
outfile << "                               ##/#/ ||/##/_/##/_#		\n";
outfile << "                             ###  /###|/ / # ###		\n";	
outfile << "                           ##__#_## | #/###_/_####		\n";
outfile << "                          ## #### #  #| /  #### ##/##	\n";	
outfile << "                           __#_--###`  |{,###---###-~	\n";	
outfile << "                                      }{				\n";	
outfile << "                                      }}{				\n";	
outfile << "                                      }}{				\n";	
outfile << "                                 ejm  {{}				\n";	
outfile << "                                , -=-~{ .-^- _			\n";	
outfile << "                                      `}				\n";	
outfile << "                                       {				\n\n\n\n";	
outfile << "               ,@@@@@@@,					\n";				
outfile << "       ,,,.   ,@@@@@@/@@,  .oo8888o.		\n";							
outfile << "    ,&%%&%&&%,@@@@@/@@@@@@,8888/88/8o		\n";							
outfile << "   ,%&/%&&%&&%,@@@/@@@/@@@88/88888/88'		\n";							
outfile << "   %&&%&%&/%&&%@@/@@/ /@@@88888/88888'		\n";							
outfile << "   %&&%/ %&%%&&@@/ V /@@' `88/8 `/88'		\n";							
outfile << "   `&%/ ` /%&'    |.|        / '|8'			\n";						
outfile << "       |o|        | |         | |			\n";						
outfile << "       |.|        | |         | |			\n";						
outfile << "jgs /// ._///_/__/  ,/_//__///.  /_//__/_	\n";								

}
