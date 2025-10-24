cmd1 | cmd2 | cmd3



			|												|
	  |			cmd3								   cmd1		cmd2
cmd1    cmd2


exec()
{
	if pipe --> exec_pipe(first_node, stdin, stdout);
	else if cmd --> exec_cmd;
}


exec_pipe(node, in_given, out_given)
{
	int	pipe_fd[2];

	pipe(pipe_fd);
	if (left_child == cmd)
		exec_cmd(left_child, in_given, pipe_created_here[out]);
	else
		exec_pipe(left_child, stdin, pipe1[out]);
	if (right_child == cmd)
		exec_cmd(right_child, pipe_created_here[in], out_given);
	else
		exec_pipe(right_child);
}


exec_cmd(node, input, output)
{
	fork();
	full_cmd_path = search_cmd_in_path(node.cmd);
	if (full_cmd_path == NULL)
		error_exit("cmd not found");
	dup2(input, stdin);
	dup2(output, stdout);
	close(input);
	close(output);
	execve(full_cmd_path, argv, env);
}
