//console.log("Welcome to notes app")
// when the user adds a note it will be added to the local storage
showtext()
let addBtn=document.getElementById("addBtn")
addBtn.addEventListener("click",function(e){

let addTxt=document.getElementById("addTxt")
let notes=localStorage.getItem("notes")
if(notes==null)
{
    notesObj=[]
}
else
{
    notesObj= JSON.parse(notes) 
}
notesObj.push(addTxt.value)    // push() is allowed only in array
localStorage.setItem("notes", JSON.stringify(notesObj))
addTxt.value=""
//console.log(notesObj)
showtext()
})
function showtext()
{
    let notes=localStorage.getItem("notes")
if(notes==null)
{
    notesObj=[]
}
else
{
    notesObj= JSON.parse(notes) 
}
let html=""
notesObj.forEach(function(element,index){
    html+=
    `<div class="card" style="width: 18rem;">
    <div class="card-body">
        <h5 class="card-title">Note ${index+1}</h5>
        <p class="card-text">${element}</p>
        <button id="${index}"onclick="deletenote(this.id)" class="btn btn-primary">Delete this note</button>
    </div>
    </div>`
    
})
let notesElm= document.getElementById("notes")   // this.id will take the id of this button which will be varying according to the index and and will give it to the deletenote()
if(notesObj.length!=0)
{
    notesElm.innerHTML=html
}
else
{
    notesElm.innerHTML="<b>Ask your first question..</b>"
}

}

// function to delete button
function deletenote(index){
  //  console.log("delete",index)
let notes=localStorage.getItem("notes")
if(notes==null)
{
    notesObj=[]
}
else
{
    notesObj= JSON.parse(notes) 
}
notesObj.splice(index,1)                        // will remove the 1st element from index= index
localStorage.setItem("notes",JSON.stringify(notesObj))
showtext()
}
let searchTxt= document.getElementById("searchTxt")
searchTxt.addEventListener("input",function(){

    let inputval= searchTxt.value.toLowerCase() 
  //  console.log("input event is fired",inputval)         // this event will fire each time you add or change new character in the string of the search box
    let notecard=document.getElementsByClassName("card")
    Array.from(notecard).forEach(function(element){
     let cardtxt=element.getElementsByTagName("p")[0].innerText
     //console.log(cardtxt)
     if(cardtxt.includes(inputval))
     {
         element.style.display="block"
     }
     else
     {
         element.style.display="none"
     }
 
    })
})
let title=getElementbyId("titlebtn")
title.addEventListener("click",function(e){
    console.warn("Please Add notes")
})




                     

