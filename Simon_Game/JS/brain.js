var buttonColors = ["red", "blue", "green", "bhagwa"];
var gamePattern = [];
var userChosenColor = "";
var userClickedPattern = [];
var gameLvl = 0;
var keyPressCounter = 0;

function nextSequence() {
    var randomNum = (Math.floor(Math.random() * 4));
    var randomChosenColour = buttonColors[randomNum];
    gamePattern.push(randomChosenColour);
    divFlash(randomChosenColour);
    playSound(randomChosenColour);
}



$(document).keypress(function () {
    ++keyPressCounter;
    if (keyPressCounter == 1) {
        nextSequence();
        ++gameLvl;
        for (let i = 0; i < document.querySelectorAll(".button").length; i++) {
            document.querySelectorAll(".button")[i].addEventListener("click", function () {
                userChosenColor = $(this).attr('id');
                userClickedPattern.push(userChosenColor);
                divFlash(userChosenColor);
                playSound(userChosenColor);
                setTimeout(function () {
                    patternMatcher(userClickedPattern.length - 1);
                }, 1000);
                $("h1").text("Level " + gameLvl);
            })
        }
        $("h1").text("Level " + gameLvl);
    }
});

var colorInput = "";
function playSound(colorInput) {
    var audio = new Audio("sounds/" + colorInput + ".mp3");
    audio.play();
}

var toBeFlashed = "";
function divFlash(toBeFlashed) {
    $("#" + toBeFlashed).addClass("flash");
    setTimeout(function () {
        $("#" + toBeFlashed).removeClass("flash");
    }, 100);
}

function patternMatcher(indexValue) {
    if (userClickedPattern[indexValue] == gamePattern[indexValue]) {
        if (userClickedPattern.length == gamePattern.length) {
            setTimeout(function () {
                nextSequence();
            }, 500);
            userClickedPattern = [];
            gameLvl++;
        }
    }
    else {
        $("h1").text("Wrong!");
        setTimeout(function () {
            $("h1").text("Restarting");
        }, 1000);
        flashOnWrong();
        startOver();
        setTimeout(function () {
            startOver();
            nextSequence();
            $("h1").text("Level " + gameLvl);
        }, 3000);
    }
}

function flashOnWrong() {
    $("body").addClass("wrong-body");
    setTimeout(function () {
        $("body").removeClass("wrong-body");
    }, 200);
    $("h1").addClass("wrong-text");
    setTimeout(function () {
        $("h1").removeClass("wrong-text");
    }, 200);
    var sound = new Audio("sounds/wrong.mp3");
    sound.play();
}

function startOver() {
    gamePattern = [];
    userClickedPattern = [];
    gameLvl = 1;
}
