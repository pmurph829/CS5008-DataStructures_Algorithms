# Mike's Vim Guide/Cheatsheet

This is my basic guide on how to use VIM. The way to learn VIM is to actually try out the different commands as you read along, and then really committing yourself to using Vim when you write source code. The more you practice, the faster you get, and you will get fast!

## What is Vim?

Vim is a text-based editor. It is widely distributed on many Unix-based platforms, so you can usually count on it being available on almost every platform you would need to edit text.

## Why Learn Vim?

Knowing how to work in a text editor that you can run in the command-line is valuable for when you work remotely. It can also be faster, and in large part, myself and many developers I know primarily only use Vim to write code!

> Tip: Sometimes when learning programming or computer science in general you can get bogged down in the content. One thing you can always practice however, is how to get faster in your editor, so when the time comes to code, you will be able to work swiftly with fewer disruptions from your tools. So what are you waiting for--read on! 

## Modes

Vim has seeral different modes of operation depending on the task you want to do. Here are the modes listed, and we will cover some more in-depth than others:

1. Insert Mode
2. Normal Mode
3. Visual Mode
4. Select Mode
5. Command-line Mode
6. Ex-Mode

You can press ESC to exit and return to the default state at any time.

### Insert mode

There are several ways to enter insertion mode.

1. `i` for 'insert' puts you in insertion mode.
2. `a` for 'append' puts you in insertion mode
3. 'c' for 'change' puts you in insertion mode.
4. 'o' also puts us in insertion mode and inserts a line break (or new line)

> Tip: Think of each of these characters that you are using more as 'operators' as opposed to 'shortcuts' that you are memorizing. As an example, trying pressing `<shift-a>` and notice that you are appending at the end of the line. `a` is generally an 'append' operation, and depending on if you are pressing shift,  you either append at a character level, or at the end of a line.

### Normal mode

### Visual mode

`v` visual character mode
`v` visual line mode
`<Ctrl-v>` visual block mode.

### Select Mode

TBD

### Command-line mode

':' puts you in command mode so you can insert commands
'/' for searching and replacing text

#### Example commands

':w' writes a file. 'Write' means to 'save' a file to disk or write data to disk.

':q' quits a file

':wq' writes and then quites a file

### Ex-Mode

TBD

## Navigation within a Vim file

One way to move around in vim is to use the arrowkeys.
Another is to use h,j,k,l;
Often times folks when learning VIM may even disable arrowkeys to truly navigate VIM!

Some other tricks for navigation are to use in normal mode:
- w - go to the next word
- e - move to the end of the current word
- b - go to the previous word

Some other shortcuts for moving around a line
- 0 - go to the start of the current line
- $ - go to the end of the current line.

However, sometimes it can be better to navigate the screen more quickly.

- `H` - Moves you to the high part of the screen
- `M` - Moves you to the middle part of the screen
- `L` - Moves you to the low part of the screen

`<Ctrl-u>` - Moves you up
`<Ctrl-d>` - Moves you down

Jump to a specific line with a number followed by the line.
- e.g. :4 moves you to the fourth line

'*' moves you forward to the next word under the cursor.
'#' moves you backward to the previous word under the cursor 

% - Moves you to the closing or opening brace that is currently highlighted

- `g:` and `g;` can cycle back to where you made a previous change, without undoing the change.

Previous changes that you made

`ctrl-o` and `ctrl-i` will cycle forward and backward between where your cursor was in the changelist.


## Navigating for Vim file

`:e` - colon followed by e and then a file name. 'e' can also be written out as 'edit' for what file you would like to edit.

## Editing multiple files at once

`:tabedit file.c` - Creates a new tab

`gt` or `gT` moves you forward and backwards in the tab

`:split` and `:vsplit` split the current window

`Ctrl+w and then arrowkey` moves you around the windows you have split.
If you want to make your split window the 'only' window open, you can use `ctrl-w o` to do so.

## Searching

`gD` Goto the declaration of a function


### Marks

You can set bookmarks in your Vim editor.

- `m{a-zA-Z}` - Sets up a custom mark
- `m{a-zA-Z}` - jump to a mark

### Tags

`:tags` - Allows you to see all of the tags
`Ctrl-J` to jump to keyword definition
`Ctrl-t` to pop from the tag stack

# Configuring your Vim

# Helpful

1. Enter command-mode
- `windo difft` will show differences in your windows

2. Toggle highlighting of text with `:hls!`

3. Want to see the working directory that you are in? `20vs .` Creates a 20 character visual split from your working directory
  - You can then navigate to this window (using `ctrl-w` and then hit `p`) to preview files. Then navigate into th previewed file, using ctrl-w, and then hit 'z' to close it or `:q`.
  
4. Getting help with help
  `:h navigation` -- VIMs built in help is wonderful!

# Resources

- [Talk on going mouseless with Vim, Tmux, and Hotkeys
](https://www.youtube.com/watch?v=E-ZbrtoSuzw) ~57 minutes in length


## Uncategorized

`:pwd` - Shows you your working directory.
`Ctrl-O / Ctrl-I` - to cycle to where you were (i.e. jump to where you last were making changes)

# Vundle

You may consider installing some plugins for vim using a tool called Vundle. See https://github.com/VundleVim/Vundle.vim for instructions on how to setup.
