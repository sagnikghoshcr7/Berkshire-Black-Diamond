import { createSlice } from "@reduxjs/toolkit";

export const counterSlice = createSlice({
    name: "counterSlice",
    initialState: {
      count: 0
    },
    reducers: {
      increment: (initialState) => {
        initialState.count = initialState.count + 1;
      },
      decrement: (initialState) => {
        initialState.count = initialState.count - 1;
      },
      incrementByAmount: (initialState, action) => {
        initialState.count = initialState.count + action.payload;
      },
      decrementByAmount: (initialState, action) => {
        initialState.count = initialState.count - action.payload;
      },
    }
  });
  
  export const { increment, decrement, incrementByAmount, decrementByAmount } = counterSlice.actions;
  
  export default counterSlice.reducer;