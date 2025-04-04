// 1.Create a Collection named "Staff". 

use staff

// 2.Insert one document into the "Staff" collection: {_id, name, age, gender, department}. 

db.staff.insertOne({
    "_id":1,
    "name":"Abdallah",
    "age":22,
    "gender":"male",
    "department":"Data Scientist"
})

// 3.Insert many documents into the "Staff" collection: 

//  Object: {_id, name, age: 20, gender: "male", department} 

//  Object: {_id, name, age: 25, gender: "female", managerName, department} 

//  Object: {_id, name, age: 15, gender, DOB} 

db.staff.insertMany([
    { "_id": 2, "name": "Mahmoud", "age": 20, "gender": "male", "department": "IT" },
    { "_id": 3, "name": "Menna", "age": 25, "gender": "female", "managerName": "Abdallah", "department": "HR" },
    { "_id": 4, "name": "Nasser", "age": 15, "gender": "male", "DOB": "2000-05-10" }
])

// 4.Query to find data from the "Staff" collection: 

// 1) Find all documents.

db.staff.find({})
 
// 2) Find documents where gender is "male". 

db.staff.find({ "gender": "male" })

// 3) Find documents with age between 20 and 25.
 
db.staff.find({ "age": { $gte: 20, $lte: 25 } })

// 4) Find documents where age is 25 and gender is "female". 

db.staff.find({ "age": 25, "gender": "female" })

// 5) Find documents where age is 20 or gender is "female". 

db.staff.find({ $or: [{ "age": 20 }, { "gender": "female" }] })

// 5.Update one document in the "Staff" collection where age is 15, set the name to "new student". 

db.staff.updateOne({ "age": 15 }, { $set: { "name": "new student" } })

// 6.Update many documents in the "Staff" collection, setting the department to "AI". 

db.staff.updateMany({}, { $set: { "department": "AI" } })

// 7.Create a new collection called "test" and insert documents from Question 3. 

db.test.insertMany([
    { "_id": 2, "name": "Mahmoud", "age": 20, "gender": "male", "department": "IT" },
    { "_id": 3, "name": "Menna", "age": 25, "gender": "female", "managerName": "Abdallah", "department": "HR" },
    { "_id": 4, "name": "Nasser", "age": 15, "gender": "male", "DOB": "2000-05-10" }
])

// 8.Try to delete one document from the "test" collection where age is 15. 

db.test.deleteOne({ "age": 15 })

// 9.try to delete all male gender 

db.test.deleteMany({ "gender": "male" })

// 10.Try to delete all documents in the "test" collection. 

db.test.deleteMany({})


dp.test.drop({})


db.test.find({})

