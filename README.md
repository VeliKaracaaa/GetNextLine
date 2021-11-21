<p class="has-line-data" data-line-start="0" data-line-end="1">Project GetNextLine</p>
<p class="has-line-data" data-line-start="2" data-line-end="10">The goal of this project is to write a function that returns a read line from a file descriptor.<br>
If there are no more lines to return, or if there is an error during the reading, the function will come back NULL.<br>
You must define a macro called READ_SIZE in your get_next_line.h file, which indicates the amount of characters to be read for each read() call.<br>
define READ_SIZE (/* value here */)<br>
The value of this macro may be changed (by another strictly positive value) during the<br>
evaluation in order to verify that you are using it correctly.<br>
Don’t forget the #ifndef directive to avoir re-defining the macro.<br>
A static variable may be used to save some datas between each call to get_next_line.</p>
