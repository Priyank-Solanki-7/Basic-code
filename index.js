const express = require("express");
const app = express();
const path = require("path");
const port = 3000;
const usermodal = require("./models/user");
app.set("view engine", "ejs");
app.use(express.json());
app.use(express.urlencoded({ extended: true }));
app.use(express.static(path.join(__dirname, "public")));
app.get("/", (req, res) => {
  res.render("page1");
});
app.get("/show", async (req, res) => {
  let user = await usermodal.find();
  res.render("show", { user: user });
});
app.post("/create", async (req, res) => {
  let { name, email, image } = req.body;
  let createuser = await usermodal.create({
    name,
    email,
    image
  });
  res.redirect("/show");
});
app.get("/delete/:id", async (req, res) => {
  let deleteuser = await usermodal.findOneAndDelete({ _id: req.params.id });
  res.redirect("/show");
});
app.get("/edit/:id", async (req, res) => {
  let edituser = await usermodal.findOne({ _id: req.params.id });
  res.render("edit",{edituser});
});
app.post("/update/:id",async(req,res)=>{
let{name,email,image}=req.body
let update = await usermodal.findOneAndUpdate({_id:req.params.id},{image,name,email});
res.redirect("/show");
});
app.listen(port);
