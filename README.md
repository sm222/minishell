# Minishell

### projet made by
[Antoine](https://github.com/sm222) and [0cculus](https://github.com/0cculus)

## for this projet you need

*  _gcc_

*  _make_

*  _readline_


## if you are missing one of those you can install them with

```bash
$ sudo apt install gcc
$ sudo apt install make
$ sudo apt install libreadline-dev
```

## how to install it use:
```bash
$ https://github.com/sm222/minishell.git && make
```
to open it use
```bash
$ ./minishell
```
## what was ask for the projet

* Display a prompt while waiting for a new command.
* Have a functional history.
* Find and launch the correct executable (based on the environment variable PATH, or on a relative or absolute path).
* Do not use more than one global variable. Think about it because you will need to justify its use.
* Do not interpret unclosed quotes or unclosed special characters. requested in the subject, such as \ (the backslash) or ; (the semicolon).
* Handle ’ (single quote) which should prevent the shell from interpreting meta-characters present in the sequence between quotes.
* Handle " (double quote) which should prevent the shell from interpreting meta-characters present in the sequence between quotation marks except the $ (dollar sign).
* Implement redirects:
  *  < should redirect the input.
  *  \> must redirect the output.
  *  << must receive a delimiter and read the given input until encountering a line containing the delimiter. However, the history does not need to be updated!
  * \>> should redirect output in append mode.
*  Implement pipes (| character). The output of each command in the pipeline is connected to the input of the following command using a pipe.
*  Manage environment variables (a $ followed by a sequence of characters) which must be substituted by their content.
*  Manage $? which must be substituted by the exit status of the last pipeline executed in the foreground.
*  Handle ctrl-C, ctrl-D and ctrl-\ which should work as in bash.
* In interactive mode:
  *  ctrl-C displays a new prompt on a new line.
  *  ctrl-D exits the shell.
  *  ctrl-\ does nothing.
* Your shell must implement the following builtins:
  *  echo and the -n option
  *  cd only with relative or absolute path
  *  pwd without any options
  *  export without any options
  *  unset without any options
  *  env without any options or arguments
  *  exit without any options
