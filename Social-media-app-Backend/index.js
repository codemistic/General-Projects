const express = require("express");
const app = express();
const jwt = require("jsonwebtoken");
const mongoose = require("mongoose");
const bcrypt = require("bcrypt");
require("dotenv").config();

const {User, Posts, Comment} = require("./models/models");
const router = require("./routes/routes");

app.use(express.json());

app.get("/", (req, res) => {    
    res.send("Welcome to Social Media API");
});

app.use("/api", router);

mongoose.connect(process.env.MONGO_URI, { useNewUrlParser: true, useUnifiedTopology: true }, () => {
    app.listen(process.env.PORT || 3000, ()=>{
        console.log(`Server Started at port ${process.env.PORT || 3000}`);
    });
});

module.exports = app; // for testing