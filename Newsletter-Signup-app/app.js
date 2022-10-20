const express = require("express");
const bodyParser = require("body-parser");
const request = require("request");
const { urlencoded } = require("body-parser");
const https = require("https");

const app = express();    //using express method as a constant app for further use

app.use(express.static("public"));    //we are using this because all our static files created like css and images can be loaded to the server using a static folder
app.use(bodyParser.urlencoded({extended: true}));     //using body-parser module to fetch user data from form 


app.get("/", function(req, res){              
    res.sendFile(__dirname+ "/signup.html")      //Sending our signup.html file to the server to be runned on port 3000
});

app.post("/", function(req, res){
    const fName = req.body.fName;       //fetching first name from form using body-parser method
    const lName = req.body.lName;       //fetching last name from form using body-parser method
    const email = req.body.email;      //fetching email from form using body-parser method
    
    const data = {
        members: [
            {
                email_address: email,
                status: "subscribed",
                merge_fields: {
                    FNAME: "firstName",
                    LNAME: "lastName"
                }

            }
        ]
    };
    const jsonData = JSON.stringify(data);   // this will convert our js object i.e data to a proper json string format, because mailchimp wants us to send data in json string format only
    
    const url= "https://us1.api.mailchimp.com/3.0/lists/f74a8a30f1";  //mailchimp url+ id

    const options={
        method: "POST",
        auth: "Reetesh:e7d188037f7fbabebeabbe7cab0436fb-us1"   //mailchimp api key
    }

    const request = https.request(url, options, function(response){

        if(response.statusCode === 200){
            res.sendFile(__dirname + "/success.html");
        }
        else{
            res.sendFile(__dirname + "/failure.html");
        }

        response.on("data", function(data){
            console.log(JSON.parse(data));
        })
    })
    request.write(jsonData);
    request.end();
})

//if signup failed redirecting to the root page by home route
app.post("/failure", function(req, res){
    res.redirect("/");
})

app.listen(3000, function(){
    console.log("Server is running on port 3000")
})

//API key
//e7d188037f7fbabebeabbe7cab0436fb-us1

//List id
// f74a8a30f1