import React, { useState } from 'react';

function Movie({ title, director, year, studio, poster }) {
  return (
    <div style={{ border: '1px solid gray', padding: '15px', margin: '10px', width: '250px', borderRadius: '8px' }}>
      <img src={poster} alt={title} style={{ width: '100%', borderRadius: '4px' }} />
      <h2>{title}</h2>
      <p><strong>Режисер:</strong> {director}</p>
      <p><strong>Рік випуску:</strong> {year}</p>
      <p><strong>Кіностудія:</strong> {studio}</p>
    </div>
  );
}

function App() {
  const [movies, setMovies] = useState([
    {
      id: 1,
      title: "Інтерстеллар",
      director: "Крістофер Нолан",
      year: 2014,
      studio: "Paramount Pictures",
      poster: "https://via.placeholder.com/250x350?text=Interstellar"
    }
  ]);

  const [title, setTitle] = useState('');
  const [director, setDirector] = useState('');
  const [year, setYear] = useState('');
  const [studio, setStudio] = useState('');
  const [poster, setPoster] = useState('');

  const addMovie = (e) => {
    e.preventDefault();
    
    const newMovie = {
      id: Date.now(),
      title: title,
      director: director,
      year: year,
      studio: studio,
      poster: poster || "https://via.placeholder.com/250x350?text=No+Poster"
    };

    setMovies([...movies, newMovie]);
    
    setTitle('');
    setDirector('');
    setYear('');
    setStudio('');
    setPoster('');
  };

  return (
    <div style={{ fontFamily: 'sans-serif', padding: '20px' }}>
      <h1>Улюблені фільми</h1>
      
      <form onSubmit={addMovie} style={{ marginBottom: '30px', display: 'flex', flexDirection: 'column', width: '300px', gap: '10px' }}>
        <input 
          type="text" 
          placeholder="Назва фільму" 
          value={title} 
          onChange={(e) => setTitle(e.target.value)} 
          required 
        />
        <input 
          type="text" 
          placeholder="Режисер" 
          value={director} 
          onChange={(e) => setDirector(e.target.value)} 
          required 
        />
        <input 
          type="number" 
          placeholder="Рік випуску" 
          value={year} 
          onChange={(e) => setYear(e.target.value)} 
          required 
        />
        <input 
          type="text" 
          placeholder="Кіностудія" 
          value={studio} 
          onChange={(e) => setStudio(e.target.value)} 
          required 
        />
        <input 
          type="text" 
          placeholder="Посилання на постер (необов'язково)" 
          value={poster} 
          onChange={(e) => setPoster(e.target.value)} 
        />
        <button type="submit" style={{ padding: '8px', cursor: 'pointer' }}>Додати фільм</button>
      </form>

      <div style={{ display: 'flex', flexWrap: 'wrap' }}>
        {movies.map((movie) => (
          <Movie 
            key={movie.id} 
            title={movie.title} 
            director={movie.director} 
            year={movie.year} 
            studio={movie.studio} 
            poster={movie.poster} 
          />
        ))}
      </div>
    </div>
  );
}

export default App;
