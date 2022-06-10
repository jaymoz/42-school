#include "Bot.hpp"

std::vector<std::string> Bot::split_args(std::string args) 
{
	std::vector<std::string> result;
	size_t pos = 0;
	size_t newPos = 0;
	unsigned long spaceSkip = args.length();

	while (args[spaceSkip] == ' ' && spaceSkip != 0) {
		spaceSkip--;
	}
	if (spaceSkip != 0) {
		args = args.substr(0, spaceSkip + 1);
	}

	for (int i = 0; newPos != std::string::npos; i++) {
		newPos = args.find(',', pos);
		if (newPos == std::string::npos)
			result.push_back(args.substr(pos));
		else
			result.push_back(args.substr(pos, newPos - pos));
		pos = newPos + 1;
	}
	return result;
}

void   Bot::ft_process_commands(std::string arg)
{
    std::string arr[3] = {"JOKE", "HELP", "INFO"};
    void (Bot::*funcptr[3])() = {&Bot::ft_joke_command, &Bot::ft_help_command,&Bot::ft_info_command};
    for (size_t i = 0; i < 3; i++)
    {
        if (arg == arr[i])
        {
            (this->*funcptr[i])();
            break ;
        }
    }
  
}

void    Bot::ft_joke_command()
{
    srand(time(NULL));
    int option = rand() % this->_jokes.size();
    for (int i = 0; i < (int)this->_jokes.size(); i++)
    {
        if (option == i)
        {
            send(this->_socketFd, this->_jokes[i].c_str(), this->_jokes[i].size() + 1, 0);
        }
    }
}

void    Bot::ft_help_command()
{
    std::string reply =  "Hey there i am an IRCBOT. The following commands are valid: HELP, JOKE, INFO\r\n";
    send(this->_socketFd, reply.c_str(), reply.size() + 1, 0);
}

void    Bot::ft_info_command()
{
    std::string reply = "BOT NICKNAME: "+ this->_nickname + "\r\n" + "BOT USERNAME: " + this->_username + "\r\n";
    send(this->_socketFd, reply.c_str(), reply.size() + 1, 0);
}

void    Bot::ft_set_jokes()
{
    std::string first = "Two bytes meet.  The first byte asks, \"Are you ill?\" The second byte replies, \"No, just feeling a bit off.\"\n";

    std::string second = "How many programmers does it take to change a light bulb? None! It is a hardware problem)\n";

    std::string third = "Why do programmers always mix up Halloween and Christmas? Because Oct 31 equals Dec 25.\n";

    std::string fourth = "Programming is like sex: One mistake and you have to support it for the rest of your life.\n";

    std::string fifth = "There are three kinds of lies: Lies, damned lies, and benchmarks.\n";

    std::string seventh = "My girlfriend told me I care more about my programming job than about her. I told her she is the #1 thing I care about\n";

    std::string eighth = "Roses are Red, Violets are Blue, Unexpected Indent In line 22\n";

    std::string nineth = "If my wife thinks I'm obsessed with programming, she's crazy. Endif\n";
    std::string tenth = "An intern recently started working for an IT programming firm. Everyday he went into work he was always harassed by his peers, they kept saying he was never being true always being false. So I had to step in, I could not let them keep Boolean him.\n";

    std::string eleven = std::string("I am so good at programming I do not even need to test before I ship code.Sent my program last week and have not heard of any problems since!\n\t\t\t") + 
                            std::string("Signed,Richard Junior Helicopter Auto-Pilot Software Developer\n");

    std::string arr[10]= {first,second,third,fourth,fifth,seventh,eighth,nineth,tenth,eleven};
    for (int i = 0; i < 10; i++)
    {
        this->_jokes.push_back(arr[i]);
    }
}