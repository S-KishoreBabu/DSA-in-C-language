const express=require('express')
const app=express()
const bodyParser=require('body-parser')
app.use(bodyParser.json())

const data=[
      {
    id: 1,
    name: "Laptop",
    price: 60000,
    quantity: 1
  },
  {
    id: 2,
    name: "Mobile Phone",
    price: 25000,
    quantity: 2
  },
  {
    id: 3,
    name: "Headphones",
    price: 3000,
    quantity: 1
  },
  {
    id: 4,
    name: "Keyboard",
    price: 1500,
    quantity: 1
  },
  {
    id: 5,
    name: "Mouse",
    price: 800,
    quantity: 3
  }
]
app.get('/',(req,res)=>{res.json(data)})

app.post('/',(req,res)=>{
    console.log(req.body)
    data.push(req.body)
    res.json(data)
})

app.patch("/:index",(req,res)=>{
    const index = req.params.index
    data[index] = {
        ...data[index],
        ...req.body
    }
    res.json(data)
})

app.delete("/:index",(req,res)=>{
    data.splice(req.params.index,1)
    res.json(data)
})

app.put("/:index",(req,res)=>{
    data[req.params.index]=req.body
    res.json(data)
})

app.listen(3000,()=>{console.log('Server running on port 3000')})