const startingTime=5;
let time=5;

setInterval(updateCountdown,1000);

function updateCountdown(){
    timeBox.innerText=`${time}`;
    if(time>0){
        time--;
    }else{
        mainBox.style.display = "none";
        finalScore.innerText="🎉"+score+"🎉";
    }
}