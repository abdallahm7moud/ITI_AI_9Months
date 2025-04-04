// 1. Provide the MongoDB code for enforcing JSON schema validation
//    when creating a collection named "employees" with required fields 
//    "name," "age" (min. 18), and "department" (limited to ["HR," "Engineering," "Finance"]).

db.createCollection("employees", {
  validator: {
    $jsonSchema: {
      bsonType: "object",
      required: ["name", "age", "department"],
      properties: {
        name: {
          bsonType: "string",
          description: "must be a string and is required"
        },
        age: {
          bsonType: "int",
          minimum: 18,
          description: "must be an integer and at least 18"
        },
        department: {
          bsonType: "string",
          enum: ["HR", "Engineering", "Finance"],
          description: "must be one of the predefined departments"
        }
      }
    }
  }
})


// 2. Find documents where the "tags" field exists.

db.inventory.find({ tags: { $exists: true } })


// 3. Find documents where the "status" field has a value in [A, B] using both the `$in` , `$or` operators.

// Using $in
db.inventory.find({ status: { $in: ["A", "B"] } })

// Using $or
db.inventory.find({ $or: [{ status: "A" }, { status: "B" }] })


// 4. Find documents where the "tags" field does not contain values "ssl" or "security."

db.inventory.find({ tags: { $nin: ["ssl", "security"] } })

// 5. Find documents where the "qty" field is equal to 85.

db.inventory.find({ qty: 85 })

// 6. Find documents where the "tags" array contains all of the values [ssl, security] using the `$all` operator.

db.inventory.find({ tags: { $all: ["ssl", "security"] } })

// 7. Find documents where the "tags" array has a size of 3.

db.inventory.find({ tags: { $size: 3 } })

// 8. Find documents where the "tags" field is of type array.

db.inventory.find({ tags: { $type: "array" } })

// 9. Update the "item" field in the "paper" document, setting "size.uom" to "meter" and using the `$currentDate` operator.
//    a. Also, use the upsert option and change filter condition item:”paper”.

db.inventory.updateOne(
  { item: "paper" },
  { 
    $set: { "size.uom": "meter" },
    $currentDate: { lastModified: true }
  },
  { upsert: true }
)

//    b. Use the `$setOnInsert` operator.

db.inventory.updateOne(
  { item: "paper" },
  {
    $set: { "size.uom": "meter" },
    $setOnInsert: { createdBy: "Abdallah" },
    $currentDate: { lastModified: true }
  },
  { upsert: true }
)


//    c. Try `updateOne`, `updateMany`, and `replaceOne`.

// updateOne
db.inventory.updateOne(
  { item: "paper" },
  { $set: { "size.uom": "meter" } }
)

// updateMany
db.inventory.updateMany(
  { item: "paper" },
  { $set: { "size.uom": "meter" } }
)

// replaceOne
db.inventory.replaceOne(
  { item: "paper" },
  { item: "paper", size: { uom: "meter" } }
)


// 10. Insert a document with incorrect field names "neme" and "ege," then rename them to "name" and "age".

db.inventory.insertOne({ neme: "Abdallah", ege: 22 })

db.inventory.updateOne(
  { neme: "Abdallah" },
  { 
    $rename: { "neme": "name", "ege": "age" } 
  }
)

db.inventory.find({name: "Abdallah" })

// 11. Try to reset any document field using the `$unset` function.

db.inventory.updateOne(
  { item: "paper" },
  { $unset: { "size.uom": "" } }
)

db.inventory.find({item: "paper" })

// 12. Try update operators like `$inc`, `$min`, `$max`, and `$mul` to modify document fields.

// Increment a field by 5
db.inventory.updateOne({ item: "paper" }, { $inc: { qty: 5 } })

// Set minimum value (if the new value is smaller, update it)
db.inventory.updateOne({ item: "paper" }, { $min: { qty: 8 } })

// Set maximum value (if the new value is greater, update it)
db.inventory.updateOne({ item: "paper" }, { $max: { qty: 100 } })

// Multiply a field by 2
db.inventory.updateOne({ item: "paper" }, { $mul: { qty: 2 } })






