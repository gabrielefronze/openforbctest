////////////////////////////////////////////////////////////////////////////////////////
//  ▄████▄   ▄▄▄       ▄████▄   ██░ ██ ▓█████  ███▄ ▄███▓▓█████ 
// ▒██▀ ▀█  ▒████▄    ▒██▀ ▀█  ▓██░ ██▒▓█   ▀ ▓██▒▀█▀ ██▒▓█   ▀ 
// ▒▓█    ▄ ▒██  ▀█▄  ▒▓█    ▄ ▒██▀▀██░▒███   ▓██    ▓██░▒███   
// ▒▓▓▄ ▄██▒░██▄▄▄▄██ ▒▓▓▄ ▄██▒░▓█ ░██ ▒▓█  ▄ ▒██    ▒██ ▒▓█  ▄ 
// ▒ ▓███▀ ░ ▓█   ▓██▒▒ ▓███▀ ░░▓█▒░██▓░▒████▒▒██▒   ░██▒░▒████▒
// ░ ░▒ ▒  ░ ▒▒   ▓▒█░░ ░▒ ▒  ░ ▒ ░░▒░▒░░ ▒░ ░░ ▒░   ░  ░░░ ▒░ ░
//   ░  ▒     ▒   ▒▒ ░  ░  ▒    ▒ ░▒░ ░ ░ ░  ░░  ░      ░ ░ ░  ░
// ░          ░   ▒   ░         ░  ░░ ░   ░   ░      ░      ░   
// ░ ░            ░  ░░ ░       ░  ░  ░   ░  ░       ░      ░  ░
// ░                  ░                                         
//
// Create a cache class able to store 5 keys within.
// Values must be arranged from the most recently used key to least recently used key.
//
// Assume the data to cache is the following array:
//
// ["A", "B", "C", "D", "E", "F", "G", "H", "I"]
//
// Assume at a given point the internal cache state is (key-value representation):
//
// [1:"A", 4:"D", 6:"F", 2:"B", 9:"I"]
//
// In case the next call is via key "6" (cache hit) the cache should return "F" without
// accessing the data array. The cache state changes as follows:
//
// [6:"F", 1:"A", 4:"D", 2:"B", 9:"I"]
//
// In case the next call is "8" (cache miss) the cache should retrieve "H" from the data
// array, return it and change its state as follows:
//
// [8:"H", 6:"F", 1:"A", 4:"D", 2:"B"]
//
// Bonus: make the cache able to act on a underlying data array containing ANY data type
//
// Bonus 2: abstract the cache in order to accept C and std arrays and std vectors as
//          underlying data structures
// 
////////////////////////////////////////////////////////////////////////////////////////