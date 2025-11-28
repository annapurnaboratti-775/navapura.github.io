// SIMPLE PARALLAX
document.addEventListener("mousemove", (e) => {
  const x = e.clientX / window.innerWidth;
  const y = e.clientY / window.innerHeight;

  document.querySelector(".c1").style.transform = `translate(${x * 20}px, ${y * 20}px)`;
  document.querySelector(".c2").style.transform = `translate(${x * -30}px, ${y * -30}px)`;
  document.querySelector(".c3").style.transform = `translate(${x * 15}px, ${y * -15}px)`;
});

// TILT EFFECT
document.querySelectorAll("[data-tilt]").forEach(card => {
  card.addEventListener("mousemove", (e) => {
    const rect = card.getBoundingClientRect();
    let x = e.clientX - rect.left;
    let y = e.clientY - rect.top;

    let rotX = (y - rect.height / 2) / 20;
    let rotY = (x - rect.width / 2) / -20;

    card.style.transform = `rotateX(${rotX}deg) rotateY(${rotY}deg)`;
  });

  card.addEventListener("mouseleave", () => {
    card.style.transform = `rotateX(0deg) rotateY(0deg)`;
  });
});
