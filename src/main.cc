#include <iostream>
#include <vector>
#include <sstream>

#define MULTIPLY 1
#define DIVIDE 2
#define ADD 3
#define MINUS 4
#define NUMBER 5

struct Token
{
	size_t position;
	char content;
	int action;
};

int main(int argc, char const* argv[])
{
	std::vector<Token> tokens;
	std::string cmd;

	std::cout << "In: ";

	std::getline(std::cin, cmd);

	for (size_t i = 0; i < cmd.size(); i++)
	{
		Token token;

		token.position = i;

		if (cmd[i] == '*')
		{
			token.content = cmd[i];
			token.action = MULTIPLY;
			tokens.push_back(token);
		}
		else if (cmd[i] == '/')
		{
			token.content = cmd[i];
			token.action = DIVIDE;
			tokens.push_back(token);
		}
		else if (cmd[i] == '+')
		{
			token.content = cmd[i];
			token.action = ADD;
			tokens.push_back(token);
		}
		else if (cmd[i] == '-')
		{
			token.content = cmd[i];
			token.action = MINUS;
			tokens.push_back(token);
		}
		else if (isdigit(cmd[i]))
		{
			token.content = cmd[i];
			token.action = NUMBER;
			tokens.push_back(token);
		}
	}


	for (size_t i = 0; i < tokens.size(); i++)
	{
		auto first = tokens[i - 1].content - 48;
		auto second = tokens[i + 1].content - 48;

		switch (tokens[i].action)
		{
		case MULTIPLY:
			std::cout << "Out: " << first * second << std::endl;
			break;
		case DIVIDE:
			std::cout << "Out: " << first / second << std::endl;
			break;
		case ADD:
			std::cout << "Out: " << first + second << std::endl;
			break;
		case MINUS:
			std::cout << "Out: " << first - second << std::endl;
			break;

		default:
			break;
		}
	}

	return 0;
}
