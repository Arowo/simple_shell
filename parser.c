
/**
 * parser - separates command from arguments passed
 *
 * @buffer: holds user's entered command
 * @cmd: pointer to the array where commands will be stored
 *
 * Return: void
 */

void parser(char *buffer, char **cmd)
{
	char *ptr;
	int i = 0;

	ptr = _strtok(buffer, " \a\r\t\n");

	while (ptr)
	{
		if (ptr[0] == '#')
		{
			cmd[i] = NULL;
			return;
		}

		cmd[i] = ptr;
		ptr = _strtok(NULL, " \n");
		i++;
	}

	cmd[i] = NULL;

}
