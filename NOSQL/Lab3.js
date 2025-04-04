
// 1. Try Export any Collection and import it into new Collection using Robo 3T


// 2.Calculate the total revenue for product from sales collection documents within 
//   the date range '01-01-2020' to '01-01-2023' and then sort them in descending order by total revenue.
//    a.	Total Revenue=  Sum (Quantity * Price)

db.sales.aggregate([
  {
    "$match": {
      "date": {
        "$gte": ISODate("2020-01-01"),
        "$lte": ISODate("2023-01-01")
      }
    }
  },
  {
    "$group": {
      "_id": "$product",
      "totalRevenue": { "$sum": { "$multiply": ["$quantity", "$price"] } }
    }
  },
  { "$sort": { "totalRevenue": -1 } }
])


// 3. Try Query 2 using Robo 3T using aggregate wizard and insert result into new collection named “newColl”

db.sales.aggregate([
  {
    "$match": {
      "date": {
        "$gte": ISODate("2020-01-01"),
        "$lte": ISODate("2023-01-01")
      }
    }
  },
  {
    "$group": {
      "_id": "$product",
      "totalRevenue": { "$sum": { "$multiply": ["$quantity", "$price"] } }
    }
  },
  { "$sort": { "totalRevenue": -1 } },
  { "$out": "newColl" }
])


// 4. Calculate the average salary for employees for each department from the employee’s collection.

db.employees.aggregate([
  {
    "$group": {
      "_id": "$department",
      "avgSalary": { "$avg": "$salary" }
    }
  }
])

// 5. Use likes Collection to calculate max and min likes per title

db.likes.aggregate([
  {
    "$group": {
      "_id": "$title",
      "maxLikes": { "$max": "$likes" },
      "minLikes": { "$min": "$likes" }
    }
  }
])


// 6. Get inventory collection Count , countDocuments

db.inventory.count()

db.inventory.countDocuments({})

db.inventory.find({})

// 7. Display 5 documents only from inventory collection

db.inventory.find().limit(5)

// 8. Count numbers of large Pizza size from orders collection  [using $count inside aggregate function]

db.orders.aggregate([
  { "$match": { "size": "large" } },
  { "$count": "largePizzaOrders" }
])

