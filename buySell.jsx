import React, { Component } from "react";
import "./buySell.css";

class BuySell extends Component {
  render() {
    return (
      <React.Fragment>
        <div className="btn">
          <button onClick={this.props.onBuy} className="btn-buy">
            BUY
          </button>
          <button onClick={this.props.onSell} className="btn-sell">
            SELL
          </button>
        </div>
      </React.Fragment>
    );
  }
}

export default BuySell;
