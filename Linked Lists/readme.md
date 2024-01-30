- Let the user use a character to choose the action.  
  a: arrival  
  l: landing\
  s: searching\
  p: printing\
  q: quit  
- When "arrival", let the user enter a plane ID, arrival time, and landing time interval requirement.  
- When "landing", delete the first plane in the queue, and also show the plane ID and the landing time of this plane.  
- When "quit", quit the program.
- When "searching", let the user enter a plane ID, and search this plane ID through the list.
  - Implement the searching action in a function.
  - If this plane ID is in the list, show all fields of this plane.
  - Otherwise show that the plane ID is not found in the list.
- When "printing", print all fields of all planes in the list.
