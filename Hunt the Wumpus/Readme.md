# Introduction
Hunt the Wumpus is a game set inside the cave of the Wumpus, a scary, gold-hoarding monster who likes to eat people who disturb its sleep. The player's goal is to guide an adventurer to kill the Wumpus, find its hidden gold, and escape alive. The Wumpus lives in a large cave of rooms arranged in a grid, where each room has four tunnels leading to the rooms to the north, east, south, and west. The adventurer starts the game in a random empty room in the Wumpus’ cave. Her starting position is also the location of the escape rope that she must use to escape after she's completed her task. Each room may be empty, or it may contain one (and only one) of four "events" (all described below): two kinds of dangerous hazards, the terrifying Wumpus, and the gold treasure. When the adventurer is in a room that’s adjacent to one containing an "event", the player will receive a percept (a message) to inform them about the event the adventurer is close to. If the adventurer perishes while searching for the Wumpus, the player should be presented with the option to start the game over with the same cave configuration, start the game over with a new random cave configuration, or quit the game entirely. The player wins the game if they can safely guide the adventurer through the cave to kill the Wumpus, pick up the gold, and make it back to the escape rope unharmed!
Note: If you enter the cave, retrieve the gold, and escape without killing the Wumpus, that's okay too. The player still wins.

# Game elements
## The adventurer
Each turn you may take one of two actions to guide the adventurer:

Move: You can move through a tunnel to an adjacent room.

Fire an Arrow: The adventurer begins the game with three arrows. As long as the adventurer still has at least one arrow, the player can choose to fire one in any direction (i.e. north, south, east, or west). The arrow continues flying in the same direction until it hits a wall or travels through three rooms. If the arrow enters the Wumpus’ room, it pierces the Wumpus’ heart and kills the monster. As noted above, if you want to design the game such that the player can win by safely retrieving the gold (and not killing the Wumpus), that's okay too.

## The Wumpus
Usually, the Wumpus is peacefully asleep in its cave. Two things wake the Wumpus up, however: the adventurer entering its room or shooting an arrow and missing it. If the Wumpus wakes up while in the same room as the adventurer, the Wumpus will angrily eat the adventurer, ending the game. If the Wumpus just wakes up from hearing an arrow being fired, though, there’s a 75% chance it will move to a random empty room in the cave to avoid being found.

## Hazards
There are two kinds of hazards in the Wumpus' cave:

Bottomless pits: Two of the cave's rooms have bottomless pits in them. If the adventurer enters a room with a bottomless pit, she falls in and dies, and the player loses.

Super bats: Two rooms have super bats. If the adventurer enters a room that contains super bats, an angry bat grabs her and takes her to some other room at random (which could be dangerous!).

## The gold
The gold is a treasure sitting in a room that contains neither a hazard nor the Wumpus. If the adventurer is in a room containing the gold, she automatically picks it up and takes it with her.

## Percepts
When the adventurer is in a room directly adjacent to to a room containing an "event", the player receives the following messages:

Wumpus: "You smell a terrible stench."
Super bats: "You hear wings flapping."
Bottomless pit: "You feel a breeze."
Gold: "You see a glimmer nearby."
Notice that there’s no percept for the escape rope! That means the player will have to remember where they started and find their way back to that tile after they’ve completed their task.

As an example of how the percepts work, if the adventurer is standing in an empty room with the Wumpus one room to the North, the Gold one room to the East, and Bats two rooms to the South, they would receive the following messages at the beginning of their turn:

You smell a terrible stench.
You see a glimmer nearby.
Remember, the percepts don’t tell you where the hazard or gold is, just that it’s somewhere close!
