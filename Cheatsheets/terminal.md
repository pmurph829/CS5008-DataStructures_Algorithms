Excellent talk on Mastering the Linux Command Line: https://www.youtube.com/watch?v=qmh7Uppd3x0

## Help

man, help, -h, --help

## Basics

ls, cd, cp, mv

- clear
- pipes
  - example: echo "hello" | rev

## Navigation

- tab completion
  - (Type a charater then hit 'tab key' on keyboard)
- Ctrl-a to go to the beginning of a line
- Ctrl-e to go to the end of aline
- ctrl-l to clear the screen
- ctrl-c to terminate a command
- ctrl-z to suspend a command
- ctrl-d to exit 'instead of typing in exit'
- cd -
- find
  - `find . -name '*.log' -size +5k` Find files that end in .log and are greater than 5 kilobytes
- locate - Searches a database for items
  - `locate gcc`
- which - Tells you which version of a program is executing
  - `which gcc`

## Shortcuts

- `echo hello for the {1..10}th time` This is an 'exapnsion' on the command.

## Execution

- exec

## History

- up arrow, down arrow
- history, !! and !<number>
- ctrl+r (Reverse-i-search) (Start typing after)

## File Processing
- file - Useful or telling you what type of file you are using (sometimes files don't have extensions for example)
- diff - Useful for comparing two files
  - `diff file1 file2 --color --side-by-side`
- touch
- vim

## Disk management

- `du -h *` - Reports on all file sizes in the directory.

## Text Manipulation

- rev
  - Reverses text
- less (view a file)
  - Ctrl-G goes to the end
- cut
- awk
- sed
- sort
- uniq

## Networking

- ssh
  - Can create a key to speed up your login process.
- ifconfig - returns ip addres (inet)
- ping
  `ping www.google.com`
- telnet
- curl
- scp - A way to copy files
- sftp
- rsync - Synchronize a local folder to a remote one.


## Utility

- date
  - `date`
- cal (Calendar)
- bc (calculator)


## Monitoring

- watch `watch -n 1 ps` 
  - Execute a command every second.
- top
- strace
- pidof
  - e.g. if you have lots of vim's running 
  - `echo $(pidof vim)`
- vmstat


## Configuration

- .profile
- alias - Can create your own commands or shortcuts


## Simple shell scripts

```bash
# Filename: echoarg.sh
# Run with: sh echoarg.sh my1stargument
#/bin/bash

ARGS=$1

echo $1
```

