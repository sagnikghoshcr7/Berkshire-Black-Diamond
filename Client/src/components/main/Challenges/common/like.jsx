import React from "react";
import "./like.css";

const Like = (props) => {
  return (
    <div
      onClick={() => props.onLike(props.solution1)}
      className={props.solution2 ? "like" : "like-green"}
    ></div>
  );
};

export default Like;
