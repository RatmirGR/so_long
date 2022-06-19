<h3>Project name:</h3>
<h2> so_long</h2>

<p><b>Project description:</b></p>
This project is a small 2D game with minilibx. Its purpose is to work with textures, sprites, and some other very basic gameplay elements.

<p><b>Task:</b></p>
<p>Your project must comply with the following rules:</p>
<p>• You must use the MiniLibX. Either the version available on the school machines, or installing it using its sources.</p>
<p>• You have to turn in a Makefile which will compile your source files. It must not relink.</p>
<p>• Your program has to take as parameter a map description file ending with the .ber extension.</p>

<p>Game</p>
<p>The player’s goal is to collect every collectible present on the map, then escape chosing the shortest possible route.</p>
<p>• The W, A, S, and D keys must be used to move the main character.</p>
<p>• The player should be able to move in these 4 directions: up, down, left, right.</p>
<p>• The player should not be able to move into walls.</p>
<p>• At every move, the current number of movements must be displayed in the shell.</p>
<p>• You have to use a 2D view (top-down or profile).</p>
<p>• The game doesn’t have to be real time.</p>
<p>• Although the given examples show a dolphin theme, you can create the world you want.</p>

<p>Graphic management</p>
<p>• Your program has to display the image in a window.</p>
<p>• The management of your window must remain smooth (changing to another window, minimizing, and so forth).</p>
<p>• Pressing ESC must close the window and quit the program in a clean way.</p>
<p>• Clicking on the cross on the window’s frame must close the window and quit the program in a clean way.</p>
<p>• The use of the images of the MiniLibX is mandatory</p>

<p>Map</p>
<p>The map has to be constructed with 3 components: walls, collectibles, and free space.</p>
<p>• The map can be composed of only these 5 characters:</p>
<p> 0 for an empty space,</p>
<p> 1 for a wall,</p>
<p> C for a collectible,</p>
<p> E for a map exit,</p>
<p> P for the player’s starting position.</p>

<p>• The map must contain at least 1 exit, 1 collectible, and 1 starting position.</p>
<p>• The map must be rectangular.</p>
<p>• The map must be closed/surrounded by walls. If it’s not, the program must return an error.</p>
<p>• You don’t have to check if there’s a valid path in the map.</p>
<p>• You must be able to parse any kind of map, as long as it respects the above rules</p>

<p>Bonus part</p>
<p>Usually, you would be encouraged to develop your own original extra features. However, there will be much more interesting graphic projects later. They are waiting for you!!</p>
<p>Don’t lose too much time on this assignment!</p>
<p>You are allowed to use other functions to complete the bonus part as long as their use is justified during your evaluation. Be smart!</p>
<p>You will get extra points if you:</p>
<p>• Make the player lose when they touch an enemy patrol.</p>
<p>• Add some sprite animation.</p>
<p>• Display the movement count directly on screen instead of writing it in the shell.</p>

