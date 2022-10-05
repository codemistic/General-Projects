import React from 'react';

export const Notes = (props) => {
    return (
        <>
            <label className='fw-bold form-label'>Notes:</label>
            <textarea
                className='form-control'
                name='notes'
                id='notes'
                cols='30'
                rows='1'
                value={props.notes}
                onChange={(e) => props.setNotes(e.target.value)}
                placeholder='Thanks for your Business!!'
            ></textarea>
        </>
    );
};
