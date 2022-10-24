import { createAsyncThunk, createSlice } from "@reduxjs/toolkit";
import axios from "axios";

export const fetchPostById = createAsyncThunk('fetchPostByIdThunk', async(id)=> {
    try {
      const response = await axios.get(`https://jsonplaceholder.typicode.com/posts/${id}`);
      return response;
    } catch (error) {
      return error;
    }
  })

  export const fetchPostByIdSlice = createSlice({
    name: 'fetchPostByIdSlice',
    initialState: {
      post: [],
      status: 'idle',
      error: null
    },
    extraReducers: {
      [fetchPostById.pending]: (state, action) => {
        state.post = [];
        state.status = 'loading';
        state.error = null;
      },
      [fetchPostById.fulfilled]: (state, action) => {
        state.post = action.payload;
        state.status = 'success';
        state.error = null;
      },
      [fetchPostById.rejected]: (state, action) => {
        state.post = [];
        state.status = 'fail';
        state.error = 'error';
      },
    }
  })

  export default fetchPostByIdSlice.reducer;