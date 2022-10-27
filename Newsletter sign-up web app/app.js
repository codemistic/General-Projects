
/* This is importing the modules from the node.js. */
const express = require("express");
const bodyParser = require("body-parser");
const request = require("request");
const https = require("https");
const { url } = require("inspector");

/* Creating an instance of express. */
const app = express();

//script to make use of body-parser
app.use(bodyParser.urlencoded({ extended: true }));


//express.static is used when we have some folders in the local machine like here css file and image.
app.use(express.static("public"));


// the get function to get the root file from our server.
app.get("/", function (req, res) {
  res.sendFile(__dirname + "/signup.html");
});


//post request for the form in html form to send to our server.
app.post("/", function (req, res) {

    //script to store data that the user input.
  let firstname = req.body.firstname;
  let lastname = req.body.lastname;
  let email = req.body.email;

  /* This is the data that we are sending to the mailchimp server. */
  var data = {
    members: [{
        email_address: email,
        status: "subscribed",
        merge_fields: {
            FNAME: firstname,
            LNAME: lastname,
        }
    }],
  };

  // this is the data in the string format to send to the mailchimp server.
  var jsonData = JSON.stringify(data); 


  // as here we are sending data to other's server thr request method is used.
  const url = "https://us10.api.mailchimp.com/3.0/lists/b12eaac07f";

  const options = {
    method : "POST",
    auth : "pain:a36764314ddd14c2431f5467d1a94cda7-us10"
  }

  /* Sending the data to the mailchimp server. */
  const request = https.request(url, options, function(response){

    if(response.statusCode === 200){
        res.sendFile(__dirname + "/success.html");
    }else{
        res.sendFile(__dirname + "/failure.html");
    }

    response.on("data", function(data){
        console.log(JSON.parse(data));
    })
  })


  //to actually send the data to mailchimp;
  request.write(jsonData);
  request.end();

});

//post request for the try again button which redirect user to the root page.
app.post("/failure" , function(req, res){
    res.redirect("/");
})



/* Listening to the port 3000. */
app.listen(process.env.PORT || 3000, function () {
  console.log("server is running on port 3000");
});

