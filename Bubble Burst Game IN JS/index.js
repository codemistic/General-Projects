var timeBox=document.getElementById("time");
var finalScore=document.getElementById("finalScore");
var startBox=document.getElementById("start");
var mainBox=document.getElementById("main");
var endBox=document.getElementById("end");
var scoreBox=document.getElementById("score");
var startButton=document.getElementById("startButton");
var bubbles=document.querySelectorAll(".bub");
var audio = new Audio('bubblepop.wav');
var score=0;

function start() {
    startBox.style.display = "none";
    time=startingTime;
}

function refresh() {
    mainBox.style.display = "flex";
    time=startingTime;
}

// resizing and aligning items
for(var i=1;i<=10;i++){
    var bubbleid="#bub"+i+"";
    var item=document.querySelector(bubbleid);
    var size=""+Math.round(Math.random()*150)+"px";
    item.style.width=size;
    item.style.height=size;
    item.style.top=""+Math.round(Math.random()*100)+"vh";
    item.style.left=""+Math.round(Math.random()*100)+"vw";
}
function resize() {
    for(var i=1;i<=10;i++){
        var bubbleid="#bub"+i+"";
        var item=document.querySelector(bubbleid);
        var size=""+Math.round(Math.random()*150+1)+"px";
        item.style.width=size;
        item.style.height=size;
        item.style.top=""+Math.random()*100+"vh";
        item.style.left=""+Math.random()*100+"vw";
        item.style.display = "block";
    }
}
setInterval(resize,10000);

// adding eventlistener on bubbles
for(var i=0;i<10;i++){
    bubbles[i].addEventListener("click",function(){
        this.style.display = "none";
        let style = getComputedStyle(this);
        let x=style.width;
        let currScore=0;
        if(x.length===3){
                currScore+=parseInt(x[0]);
        }else if(x.length===4){
            for(let z=0;z<2;z++){
                currScore+=parseInt(x[z]);
            }
        }else{
            for(let z=0;z<3;z++){
                currScore+=parseInt(x[z]);
            }
        }
        
        score=score+150-currScore;
        scoreBox.innerText=score;
        time=startingTime;
        audio.play();
    });
}

