const mongoose = require("mongoose");

const UserSchema = new mongoose.Schema({
    username: {
        type: String,
        required: true,
        unique: true,
        trim: true,

    },
    password: {
        type: String,
        required: true,
    },
    email: {
        type: String,
        required: true,
    },
    posts: {
        type: Array,
    },      //String == Id of photo
    followers: {
        type: Array,

    },   //String == username
    following: {
        type: Array,
    },   //String == username
});

const Posts = new mongoose.Schema({
    username: {
        type: String,
        required: true,
    },
    title: {
        type: String,
        required: true,
    },
    description: {
        type: String,
        required: true,
    },
    likedBy: {
        type: Array
    },       //String == username
    comments: {
        type: Array
    },
    uploadTime: Date,    //String == comment
});

const Comments = new mongoose.Schema({
    username: {
        type: String,
        required: true,
    },
    comment: {
        type: String,
        required: true,
    },
});

module.exports = {
    User: mongoose.model("User", UserSchema),
    Posts: mongoose.model("Posts", Posts),
    Comment: mongoose.model("Comments", Comments),
};