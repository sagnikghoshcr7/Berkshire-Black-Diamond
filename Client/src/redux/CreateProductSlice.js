import { createAsyncThunk, createSlice } from "@reduxjs/toolkit";
import axios from "axios";

//dispatcher
export const addProduct = createAsyncThunk('createProductThunk', async (product) => {
    try {
        await axios.post("http://localhost:9191/addproduct/", product);
    } catch (error) {
        return error;
    }
})

//slice
export const addProductSlice = createSlice({
    name: 'createProductSlice',
    initialState: {
        status: 'idle',
        error: null
    },
    extraReducers: {
        [addProduct.pending]: (state, action) => {
            state.status = 'loading';
            state.error = null;
        },
        [addProduct.fulfilled]: (state, action) => {
            state.status = 'success';
            state.error = null;
        },
        [addProduct.rejected]: (state, action) => {
            state.status = 'fail';
            state.error = 'error';
        },
    }
})

export default addProductSlice.reducer;