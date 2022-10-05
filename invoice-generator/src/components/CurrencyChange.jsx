import React from 'react';

export const CurrencyChange = (props) => {
    return (
        <div className='mb-3'>
            <label className='fw-bold form-label'>Currency:</label>
            <select
                className='btn btn-light form-select'
                value={props.currency}
                onChange={(e) => props.setCurrency(e.target.value)}
            >
                ₹<option value='₹'>INR (Indian Rupee)</option>
                <option value='¥'>JPY (Japanese Yen)</option>
                <option value='$'>USD (United States Dollar)</option>
                <option value='£'>GBP (British Pound Sterling)</option>
                <option value='¥'>JPY (Japanese Yen)</option>
                <option value='$'>CAD (Canadian Dollar)</option>
                <option value='$'>AUD (Australian Dollar)</option>
                <option value='$'>SGD (Signapore Dollar)</option>
                <option value='¥'>CNY (Chinese Renminbi)</option>
                <option value='₿'>BTC (Bitcoin)</option>
            </select>
        </div>
    );
};
