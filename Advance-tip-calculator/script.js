/*
🌟 APP: Tip Calculator

These are the 3 functions you must use 👇
=========================================
calculateBill()
increasePeople()
decreasePeople()

These functions are hard coded in the HTML. So, you can't change their names.

These are all the DIV ID's you're gonna need access to 👇
========================================================
#1 ID 👉 'billTotalInput' = User input for bill total
#2 ID 👉 'tipInput' = User input for tip
#3 ID 👉 'numberOfPeople' = Current number of people you're splitting the bill between
#4 ID 👉 'perPersonTotal' = Total dollar value owed per person
*/

// Get global access to all inputs / divs here (you'll need them later 😘)
// bill input, tip input, number of people div, and per person total div



// Get number of people from number of people div


// ** Calculate the total bill per person **
const calculateBill = (num) => {
  // get bill from user input & convert it into a number
   let Bill = Number(document.getElementById('billTotalInput').value)

  // get the tip from user & convert it into a percentage (divide by 100)
  let tipPercentage = Number(document.getElementById('tipInput').value)/100

  // get the total tip amount
  let tipAmount = tipPercentage * Bill

  // calculate the total (tip amount + bill)
  let total = parseFloat(Bill + tipAmount).toFixed(2);
  let t = '$'+total
  // calculate the per person total (total divided by number of people)
  let finalTotal = parseFloat(total / num).toFixed(2);
  let f = '$'+finalTotal 
if(num > 1){
  document.getElementById('perPersonTotal').innerHTML = f
}else{
  document.getElementById('perPersonTotal').innerHTML = t
}

  // update the perPersonTotal on DOM & show it to user


}
let count = 1;
// ** Splits the bill between more people **
const increasePeople = () => {
  // increment the amount of people
    count++

  // update the DOM with the new number of people
  document.getElementById('numberOfPeople').innerHTML=count

  // calculate the bill based on the new number of people
calculateBill(count)
}

// ** Splits the bill between fewer people **
const decreasePeople = () => {
  // guard clause
  // if amount is 1 or less simply return
  // (a.k.a you can't decrease the number of people to 0 or negative!)
    if(count <= 1){
      return
    }

  // decrement the amount of people
  count--

  // update the DOM with the new number of people
  document.getElementById('numberOfPeople').innerHTML=count

  // calculate the bill based on the new number of people
  calculateBill(count)
}
