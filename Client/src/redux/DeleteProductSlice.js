import { createAsyncThunk, createSlice } from "@reduxjs/toolkit";
import axios from "axios";

//dispatcher
export const deleteProductById = createAsyncThunk('deleteProductThunk', async (id) => {
    try {
        await axios.delete(`http://localhost:9191/delete/${id}`);
    } catch (error) {
        return error;
    }
})

//slice
export const deleteProductByIdSlice = createSlice({
    name: 'deleteProductSlice',
    initialState: {
        status: 'idle',
        error: null
    },
    extraReducers: {
        [deleteProductById.pending]: (state, action) => {
            state.status = 'loading';
            state.error = null;
        },
        [deleteProductById.fulfilled]: (state, action) => {
            state.status = 'success';
            state.error = null;
        },
        [deleteProductById.rejected]: (state, action) => {
            state.status = 'fail';
            state.error = 'error';
        },
    }
})

export default deleteProductByIdSlice.reducer;