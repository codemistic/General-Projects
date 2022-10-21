function computerPlay(){
    let x= (Math.floor(Math.random()*100)%5);
    switch(x){
        case 0: return "rock"; break;
        case 1: return "paper"; break;
        case 2: return "scissors"; break;
        case 3: return "lizard"; break;
        case 4: return "spock"; break;
    }
}
//Function to evaluate player and computer inputs and return who wins
function evalRound(p1, p2){
    if(p1=="rock"){
        switch(p2){
            case "rock": return [-1,""]; break; 
            case "paper": return [1,"covers"]; break; 
            case "scissors": return [0,"crushes"]; break;
            case "lizard": return [0,"crushes"]; break; 
            case "spock": return [1,"vaporizes"]; break; 
        }
    }
    else if(p1=="paper"){
        switch(p2){
            case "rock": return [0,"covers"]; break; 
            case "paper": return [-1,""]; break; 
            case "scissors": return [1,"cuts"]; break;
            case "lizard": return [1,"eats"]; break; 
            case "spock": return [0,"disproves"]; break; 
        }
    }
    else if(p1=="scissors"){
        switch(p2){
            case "rock": return [1,"crushes"]; break; 
            case "paper": return [0,"cuts"]; break; 
            case "scissors": return [-1,""]; break;
            case "lizard": return [0,"decapitates"]; break; 
            case "spock": return [1,"smashes"]; break; 
        }
    }
    else if(p1=="lizard"){
        switch(p2){
            case "rock": return [1,"crushes"]; break; 
            case "paper": return [0,"eats"]; break; 
            case "scissors": return [1,"decapitates"]; break;
            case "lizard": return [-1,""]; break; 
            case "spock": return [0,"poisons"]; break; 
        }
    }
    else if(p1=="spock"){
        switch(p2){
            case "rock": return [0,"vaporises"]; break; 
            case "paper": return [1,"disproves"]; break; 
            case "scissors": return [0,"smashes"]; break;
            case "lizard": return [1,"poisons"]; break; 
            case "spock": return [-1,""]; break; 
        }
    }   
    else
        {
        console.log("invalid") ;
        return [-1];
    }
}

let p1Score;
let p2Score;
let optionButtons = document.querySelectorAll(".userOptions .option");
let computerOptionsDiv = document.querySelector(".compOptions");
let userScore = document.querySelector("#userScore");
let compScore = document.querySelector("#compScore");
let msg = document.querySelector(".message");

let paused = false;
function playRound(selection){

    //Disable the buttons. will be reenables before next round
    optionButtons.forEach(button => {
        button.disabled = true;
        button.parentElement.classList.remove('hoverable');
    })
    paused =true;

    let playerSelection = selection;
    let computerSelection = computerPlay();

    // Create the computer selection element
    let span = document.createElement('span');
    span.classList.add('optBox');
    span.setAttribute('id', "computerSelection");
    let input = document.createElement('input');
    input.setAttribute('type','image');
    input.setAttribute('src',"./assets/"+computerSelection+".png");
    input.setAttribute('disabled',"disabled");
    input.classList.add('option');
    span.appendChild(input);
    computerOptionsDiv.appendChild(span);
    span.style.transform = 'scale(1.1)';

    let roundResult = evalRound(playerSelection, computerSelection);

    if(roundResult[0] == 0){
        p1Score+=1;
    }
    else if(roundResult[0] == 1){
        p2Score+=1;
    }

    userScore.innerText = `${p1Score}`;
    compScore.innerText = `${p2Score}`;
    if(p1Score==5 || p2Score==5)
        {   
            declareResult();
            optionButtons.forEach(button => {
                button.disabled = true;
            })
        }
    msg.innerText = "Press any key to continue";

}
function prepRound(){
    if(p1Score>=5 || p2Score>=5) return;
    msg.innerText = "Pick your choice";
    let insertedCompOption = document.querySelector('#computerSelection');
    insertedCompOption.parentElement.removeChild(insertedCompOption);

    //selected contains the spans with buttons
    let selected = document.querySelectorAll(".selected");

    selected.forEach(buttonSpans =>{
        buttonSpans.classList.remove("selected");
    })
    optionButtons.forEach(button => {
        button.disabled = false;
        button.parentElement.classList.add('hoverable');
    });
}
function declareResult(){
    msg.innerText = " ";
    compSel.innerText = " ";
    if(p1Score> p2Score){
        msg.innerText = "You win!";
    }
    else{
        msg.innerText = "Computer wins!";
    }
}
function initialiseGame(){
    p1Score = 0;
    p2Score = 0;
    optionButtons.forEach(button =>{
        button.disabled=false;
        button.addEventListener('click',()=>{
            button.parentElement.classList.add('selected')
            playRound(button.getAttribute('data-key'));});
    });
    msg.innerText = "Pick your choice";
}


initialiseGame();
window.addEventListener('keydown',()=>{
    console.log('hel');
    if(paused){
        prepRound();
    }
})