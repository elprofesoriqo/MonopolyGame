 Write an implementation of Landlord's game
  The state of the game is handled by specyfing S_X -- state commands.
  E.g. S_SET_PLAYER_POS i j -- which sets the i-th player into j-th position.
  Those commands change the behaviour of the game. For example, by:
   - setting the player to given position,
   - adding new places to the board,
   - adding card to a deck, etc.
  The game [from player's perspective] is handled by handling the player commands, like:
   - movement by a random space,
   - or buying a lot where the player stands,
   - or drawing a card if a player stands on "chance" field.

  Consider: https://landlordsgame.info/games/lg-1906/lg-1906_egc-rules.html

  Initially, there are the following places, at the corresponding positions:
  0.  START
  1.  A1, worth 50
  2.  A2, worth 80
  3.  A3, worth 100
  4.  WORKHOUSE
  5.  UTILITY 1, worth 50
  6.  TRAIN 1, worth 50
  7.  JAIL
  8.  SHELTER
  9.  CHANCE
  10.  TAXES

  Commands to handle:
  - SET_N_PLAYERS n
       sets the number of players as n; you may assume that n is bounded by 10;
  - SET_PLAYER_POS i x
       sets the i-th player's position at x,
  - SET_PLAYER_TURN
       sets whose turn shall be the next one,
  - SET_PLAYER_ACCOUNT i x
       set the i-th player account as x,
  - PRINT mode
       If mode == 0:
       Print whose turn's it is and print the positions and accounts of the conesecutive players.
       If a player lost, print "LOST" instead of an account.
       If mode == 1:
       print map: print a list of fields:
       field's number, number of owener or '-' if there is no owner,
       finally print a number, let i-th msb be set into 1, if the field is occupied by the i-th player, 0 otherwise.
       In addition print a second number singnifying if the i-th player owns the field
  - MOVE x
       Move the current player by a given number of fields,
       (assume, the players are rolling the dice and providing the results).
       If a player enter an owned field, she must pay half the rent to the owner.
       If a player re-enters or passes START, then she earns 100$.
       If a player enters JAIL, she is stuck there until there is a doublet thrown;
       namely the player is able to make a MOVE and only after making a double, she is allowed to leave it.
       Immidiately after throwing the doublet, the player is moved to the shelter.
       A player may move once per her turn.
       It is assumed that the dice is 6-sided.
  - BUY
       The current player (or a higher bidder) may buy the property, provided that she stands on a free one, using auction system.
       The bids are given as BID p v -- i.e. that player p offers v, until an END command appears.
       Then the player with highest bid wins.
       A player cannot offer less, than she previously stated.
  - SELL
       The current player may sell her property, for half of the worth, at any time.
  - END_TURN
       Switches the current player to the next one
  - # ...
       Ignore all the remaining text in the line (you may assume that the # is seperated from the rest of content).
  - END_GAME
       Ends the game

The default state of the game is that there are 2 players, each starts at START, each has 200$, the first player starts.

In the case that a player has to pay another player, or bid some value at an auction and has not enough money, the game shall signal this.
Moreover, the player should be forced to SELL until her account is not negative.
If the account is negative after selling all the property, then the player loses the game.


Side observation: for now, the instruction is very basic.
Later on, there will be more things added like:
 - a possibility to add houses,
 - selling them, if needed,
 - adding more places etc,
 - making an auction, open to all players, when a player decides or is forced to sell a property.
 - de-hardcoding of the positions, prices, and types of fields.
   I.e. a possibilty to specify where is a jail, or how much properties are worth, or where are the utilites, trains etc.
Feel free to add anything you like.
