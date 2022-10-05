let currStreak = 0;
let bestStreak = 0;
doorImage1 = document.querySelector('#door1');
doorImage2 = document.querySelector('#door2');
doorImage3 = document.querySelector('#door3');
let startButton = document.querySelector("#start");
const winCounter = document.querySelector("#win");
const looseCounter = document.querySelector("#loose");

let currentPlaying = true;

const closedDoorPath = "https://s3.amazonaws.com/codecademy-content/projects/chore-door/images/closed_door.svg";
const botDoorPath = "https://s3.amazonaws.com/codecademy-content/projects/chore-door/images/robot.svg";
const beachDoorPath = "https://s3.amazonaws.com/codecademy-content/projects/chore-door/images/beach.svg" ;
const spaceDoorPath = "https://s3.amazonaws.com/codecademy-content/projects/chore-door/images/space.svg";
let numClosedDoors = 3;
let openDoor = [0, 0, 0];

const randomChoreDoorGenerator = () => {
    let choreDoor = Math.floor(Math.random() * numClosedDoors);
    openDoor[choreDoor] = botDoorPath;
  
    let nums = [0, 1, 2];
    nums.splice(nums.indexOf(choreDoor), 1);
    
    let anotherRand = Math.floor(Math.random() * 2);
                openDoor[nums[anotherRand]] = beachDoorPath;
                openDoor[nums[1 - anotherRand]] = spaceDoorPath;  
};

const startRound = () => {
    doorImage1.src = closedDoorPath;
    doorImage2.src = closedDoorPath;
    doorImage3.src = closedDoorPath;
    numClosedDoors = 3;
    startButton.innerHTML = 'Good Luck';
    currentPlaying = true;
    randomChoreDoorGenerator();
}

doorImage1.onclick = () => {
    if(!isClicked(doorImage1) && currentPlaying) {
        doorImage1.src = openDoor[0];
        playDoor(doorImage1);
    }
}
doorImage2.onclick = () => {
    if(!isClicked(doorImage2) && currentPlaying) {   
        doorImage2.src = openDoor[1];
        playDoor(doorImage2);
    }  
}
doorImage3.onclick = () => {
    if(!isClicked(doorImage3) && currentPlaying) {   
        doorImage3.src = openDoor[2];
        playDoor(doorImage3);
    }
}

startButton.onclick = startRound;


function gameOver(status) {
    if(status === 'win') {
	currStreak++;
        startButton.innerHTML = 'You win! Play Again?';
    }
    else {
	if(currStreak > bestStreak)
		bestStreak = currStreak;
	currStreak = 0;
        startButton.innerHTML = 'Game over! Play Again?';
    }
    currentPlaying = false;

    winCounter.innerHTML = "Current Streak: " + currStreak;
    looseCounter.innerHTML = "Best Streak: " + bestStreak;

}

const isBot = door => {
    if(door.src === botDoorPath)
        return true;
    else
        return false;
};

const isClicked = door => {
    if(door.src === closedDoorPath)  
        return false;
    else
        return true;
};

function playDoor(door) {
    numClosedDoors--;
    if(numClosedDoors === 0)
        gameOver('win');
    else if(isBot(door))
        gameOver();      
}

startRound();
