const Express = require("express");
const bodyParser = require("body-parser");
const CookieParser = require("cookie-parser");
const LogGameCookie = require("../serviceShared/LogGameCookie.js");

const app = Express();
app.use(CookieParser());
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));

const Port = 8082;

app.post("/fake-score", (req, res) => {
  const { user_won, user_lost, length, hash } = req.body;
  const logGameCookie = new LogGameCookie(user_won, user_lost, length);
  if (logGameCookie.hash() !== hash) {
    console.log(`INVALID HASH (${user_won}, ${user_lost}, ${length}, ${hash})`);
    res.status(403);
    res.end();
  } else {
    console.log(
      `LOGGED SCORE SUCCESSFULLY! (${user_won}, ${user_lost}, ${length}, ${hash})`
    );
    res.status(200);
    res.end();
  }
});

app.listen(Port, () => console.log("Listening on port: " + Port));
