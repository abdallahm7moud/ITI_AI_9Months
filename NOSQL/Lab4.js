// 1. Create new 
//    a. Database named Demo
//    b. collections named trainningCenter1 , trainningCenter2 
//    NOTE: trainningCenter2 will apply all quires.

use Demo

db.createCollection("trainningCenter1")
db.createCollection("trainningCenter2")

// 2. Insert documents into trainningCenter1 collection contains _id , name as firstName lastName , age , address as array , status
//    Using Variable (Array Data) and insert ONE

var ArrayData = [
  {
    _id: 1,
    name: { firstName: "Abdallah", lastName: "Mahmoud" },
    age: 22,
    address: ["123 Main St", "Apt 4B", "Egypt"],
    status: "Active"
  },
  {
    _id: 2,
    name: { firstName: "Mahmoud", lastName: "Nasser" },
    age: 25,
    address: ["456 Elm St", "Egypt"],
    status: "Pending"
  },
  {
    _id: 3,
    name: { firstName: "Mohamed", lastName: "Amr" },
    age: 24,
    address: ["789 Pine St", "Egypt"],
    status: "Inactive"
  }
]

db.trainningCenter1.insertOne(ArrayData)

db.trainningCenter1.find({})

// 3. Insert documents into trainningCenter2 collection 
//    Using Same Variable (Array Data) with same data and insert MANY

db.trainningCenter2.insertMany(ArrayData)

db.trainningCenter2.find({})

// 4. Use find. explain function (find by age field) and mention scanning type

// "stage" : "COLLSCAN"
db.trainningCenter2.find({ age: 22 }).explain()


// 5. Create index on created collection named it “IX_age” on age field 

db.trainningCenter2.createIndex({ age: 1 }, { name: "IX_age" })

// 6. Use find. explain view winning plan for index created (find by age field) and mention scanning type

// "stage" : "IXSCAN"
db.trainningCenter2.find({ age: 22 }).explain()


// 7. Create index on created collection named it “compound” on firstNsme and lastName

//    a. Try find().explain before create index and mention scanning type
// "stage" : "COLLSCAN"
db.trainningCenter2.find({ "name.firstName": "Abdallah", "name.lastName": "Mahmoud" }).explain()

//    b. Try find().explain after create index and mention scanning type
db.trainningCenter2.createIndex({ "name.firstName": 1, "name.lastName": 1 }, { name: "compound" })

// "stage" : "IXSCAN"
db.trainningCenter2.find({ "name.firstName": "Abdallah", "name.lastName": "Mahmoud" }).explain()


// 8. Try to delete from your collection where _id = 5 [insert it if not exists]


db.trainningCenter2.insertOne({
    _id: 5,
    name: { firstName: "Adham", lastName: "Assy" },
    age: 26,
    address: ["126 Main St", "Apt 4B", "Egypt"],
    status: "Active"
  })

db.trainningCenter2.deleteOne({ _id: 5 })


// 9. Delete all documents from the trainingCenter collection.

db.trainningCenter2.deleteMany({})

// 10. Drop the database and confirm its removal. Which command do you use to ensure the deletion?

db.dropDatabase()

show databases

// 11. Backup your Labs database (Mongo_ITI) 

db.serverCmdLineOpts()

//mongodump --db staff --out "D:\ITI\NOSQL\backup"

// 12. Restore the taken back-up by new DB name Called Mongo_ITI_New

//mongorestore --db ITI --dir "D:\ITI\NOSQL\backup\staff"
