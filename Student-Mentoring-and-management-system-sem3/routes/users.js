var express = require('express');
const { MongoClient } = require('mongodb');
var router = express.Router();
const {dbUrl,mongodb,MongClient, Mongoclient}=require("../bin/config");

/* GET users listing. */
router.get('/', function(req, res, next) {
  res.send('respond with a resource');
});

router.get("/all-students",async(req,res)=>{//get all the students data
  const client = await MongoClient.connect(dbUrl);
  try {
      const db = client.db("StudentMentor");
      const user = await db.collection("student").find().toArray();//finding all data present in student collection
      res.status(200).send(user);
  } catch (error) {
      res.json(error);
  }finally{
    client.close();
  }
})

router.get("/all-mentors",async(req,res)=>{// getting all mentor data
  const client = await MongoClient.connect(dbUrl);
  try {
      const db = client.db("StudentMentor");
      const user = await db.collection("mentor").find().toArray();//finding all mentors in the mentor collection
      res.status(200).send(user);
  } catch (error) {
      res.json(error);
  }finally{
    client.close();
  }
})

router.post("/mentor",async(req,res)=>{// getting the mentor details of a particular student
  const client = await MongoClient.connect(dbUrl);
  try {
      const db = client.db("StudentMentor");
      const user = await db.collection("student").findOne({"studentName":req.body.studentName});
      res.status(200).json(user);
  } catch (error) {
      res.json(error);
  }finally{
    client.close();
  }
})

router.post("/students",async(req,res)=>{//getting the students details of a particular mentor 
  const client = await MongoClient.connect(dbUrl);
  try {
      const db = client.db("StudentMentor");
      const user = await db.collection("mentor").findOne({"mentorName":req.body.mentorName});
      res.status(200).json(user);
  } catch (error) {
      res.json(error);
  }finally{
    client.close();
  }
})

router.post("/add-mentor",async(req,res)=>{//creating a new mentor with or without students data
  const client = await MongoClient.connect(dbUrl);
  try {
      const db = client.db("StudentMentor");
      const user = db.collection("mentor").insertOne(req.body);//creating mentor in db
      if(req.body.mentorStudents){//if mentor have students while creating we have to add this mentor to those students in student collection
        req.body.mentorStudents.map(async(e)=>{
          const stu = await db.collection("student").updateOne({"studentName":e},{$set:{"studentMentor":req.body.mentorName}});
        })
      }
      res.status(200).json({
        message:"Mentor Added Successfully!"
      })
  } catch (error) {
      res.status(500).json(error);
  }finally{
    client.close();
  }
})
router.post("/add-student",async(req,res)=>{// creating a student with or without mentor
  const client = await MongoClient.connect(dbUrl);
  try {
      const db = client.db("StudentMentor");
      const user = db.collection("student").insertOne(req.body);//creating new student
      if(req.body.studentMentor){//if mentor exist we have to update the student to the corresponding mentor in mentor collection
        const men = await db.collection("mentor").findOne({"mentorName":req.body.studentMentor});
        men.mentorStudents.push(req.body.studentName);//mentor students is a array hence we are extracting it and pushing the new member and updating the same
        const update = await db.collection("mentor").updateOne({"mentorName":req.body.studentMentor},{$set:{"mentorStudents":men.mentorStudents}});
      }
      res.status(200).json({
        message:"Student Added Successfully"
      })
  } catch (error) {
      res.status(500).json(error);
  }finally{
    client.close();
  }
})

router.post("/assign-students",async(req,res)=>{
  const client = await MongoClient.connect(dbUrl);
  try {
      const db = client.db("StudentMentor");
      if(req.body.mentorStudents){//updating mentor Name for all selected students
        req.body.mentorStudents.map(async(e)=>{
          const stu = await db.collection("student").updateOne({"studentName":e},{$set:{"studentMentor":req.body.mentorName}});
        })
      }
      if(req.body.mentorName){//updating students name for selected mentor
        const men = await db.collection("mentor").findOne({"mentorName":req.body.mentorName});
        //console.log(men.mentorStudents);
        req.body.mentorStudents.map((i)=>{//pushing all the students newly assigned to the selected mentor
          men.mentorStudents.push(i);
        })
        //console.log(men.mentorStudents);
        const update = await db.collection("mentor").updateOne({"mentorName":req.body.mentorName},{$set:{"mentorStudents":men.mentorStudents}});
      }
      res.status(200).json({
        message:"Mentor and Students Mapped Successfully!"
      })
  } catch (error) {
      res.status(500).json(error);
  }finally{
    client.close();
  }
})


router.post("/change-mentor",async(req,res)=>{//change the existing mentor to new mentor
  //steps involved
  //1. We are getting Student Name, mentor Name and Old mentor from frontend
  //2. Find the oldmentor and remove this student as the student mentor is changing
  //3. The deleting of student takes place with the help of splice()
  //4. After deleting updating the array of students for old mentor
  //5. Update the new mentor name for the selected student
  //6. Find the new mentor details and update the student array with this new student.
  const client = await MongoClient.connect(dbUrl);
  try {
      const db = client.db("StudentMentor");
      const men = await db.collection("mentor").findOne({"mentorName":req.body.oldMentor});//2
      men.mentorStudents.splice(men.mentorStudents.indexOf(req.body.studentName),1);//3
      const update = await db.collection("mentor").updateOne({"mentorName":req.body.oldMentor},{$set:{"mentorStudents":men.mentorStudents}});//4
      const user = await db.collection("student").updateOne({"studentName":req.body.studentName},{$set:{"studentMentor":req.body.mentorName}});//5
      const newmen = await db.collection("mentor").findOne({"mentorName":req.body.mentorName});//6
      newmen.mentorStudents.push(req.body.studentName);//6
      const newupdate = await db.collection("mentor").updateOne({"mentorName":req.body.mentorName},{$set:{"mentorStudents":newmen.mentorStudents}});//6
      res.status(200).json({
        message:"Mentor Changed Successfully!"
      })
  } catch (error) {
      res.status(500).json(error);
  }finally{
    client.close();
  }
})

module.exports = router;
