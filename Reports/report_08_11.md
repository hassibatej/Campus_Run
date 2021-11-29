#  Report for the week of November 8th 2021
After discussions with the each member of team, we've separated ourselves in two different groups working on the design of the game and on the 'back' of the game, which we will assemble later.

# Teams:

### UI design

Marie:
This week, us macOS users spent an enormous alot of time trying to find a way to get VS and SFML to work on our computers. This is currently a work in progress. Alongside this, I worked on developing the coin class, their appearance, and their properties. Next week I plan on further developing this class, and working on other aspects of the game.



Fiona:
This week, I spent a lot of time figuring out how to run the game in Visual studio (VS is not compatible with IOS so i had many issues). Regarding the code I pushed this week, I took care of the sprite attribute of the player and worked with Antonina on rendering it on screen.



Antonina: This week, I spent most of my time figuring out how to run the game on Mac by using a Windows virtual machine (Virtual Box to be specific) to run Visual Studio Code. I worked with Fiona on rendering the player and I added animations to the player class. We will be able to reuse this function to render objects and enemies in the future.



### Game engine development
Antoine Babu:
This week, I built a base for the game, making SFML run in Visual Studio. I helped around with physics, animations etc... As for commits, I implemented a hitbox class, to implement collision. Collision is not complete (we need the map to be able to iterate over the different entities). We will be able to reuse hitboxes in the future, for instance for combat. Next step on my hand is to merge everyone's code smoothly, as we all worked on our own this week, some of us without testing because of incompatibility issues.



Antoine Majoie:
This week I spent quite a bit of time to run the game (I'm on iOS and it was complicated to run SFML on Visual Studio, I ended up using my older laptop that runs on Windows). I was able to grasp a better understanding on the camera movement through research, but I have not implemented it yet. On the other hand, I added deceleration to the physics of the player, to regulate its movement.




Eve Margolis:

This week I did additional research on how to implement coins (and possible future items into our game). I started trying to find and code how to make a coin counter appear, visually, as well as take into account each coin collected. Next week I plan on finalizing this counter and adding more features.



Rojin Radmehr:

This week I made the class for obstacles and different types of platforms and the different interactions with them and their characteristics.
Next week i will complete this since i needed collision detection for some parts.


Hassiba Tej: This week, I continued researches and looked up other documentation. I implemented the part of the code that takes care of the mouvement of the cat and the way it falls when we press multiple times on the space bar, taking into account the gravity and physics in general.
I also took care of explaining how to create branches, pull request, etc.



### Whole team
- Whole team did research on their side
- Had a meeting to gather our ideas and what we found
- Looked at some libraries & ressources (SFML, Unity...)
- Set the deadline of what we wanted done for next week => working on the headers, and the code for moving a little cube on everyone's computer at least (depending on the libraries we are allowed to use
- Thoughts on the graphics we wanted to implement
- Agreed on a general meeting time for us to discuss each week
- Research on compilers


### Done this week :
This week, as a team, we ensured we had a running game engine which allowed us to move a pixelated cat forwards and backwards and which had the ability to jump. In addition, each member of our team 
began working on different and more specific aspect of the game. These included the coin class and coin counter, the basic menu user interfrace, the camera, rendering the player, hitbox and collisions, physics (making sure gravity works) and the platform and object classes.


